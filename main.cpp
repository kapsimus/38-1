#include <QApplication>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPixmap>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button(nullptr);
    QMediaPlayer player;
    QAudioOutput audioOutput;
    QPixmap pushedButton("..\\images\\button_pushed.png");
    QPixmap unpushedButton("..\\images\\button_unpushed.png");

    player.setAudioOutput(&audioOutput);
    player.setSource(QUrl::fromLocalFile("..\\sound\\click.mp3"));
    button.setIcon(unpushedButton);
    button.setIconSize(unpushedButton.rect().size());
    button.show();

    QObject::connect(&button, &QPushButton::pressed, [&button, &player, &pushedButton](){
        button.setIcon(pushedButton);
        player.stop();
        player.play();
    });
    QObject::connect(&button, &QPushButton::released, [&button, &unpushedButton](){
        button.setIcon(unpushedButton);
    });
    return QApplication::exec();
}
