#ifndef WIDGETMEDIA_H
#define WIDGETMEDIA_H

#include <QMainWindow>
#include <QSlider>

namespace Ui {
    class WidgetMedia;
}

class WidgetMedia : public QMainWindow {
    Q_OBJECT
public:
    WidgetMedia(QWidget *parent = 0);
    ~WidgetMedia();
	QSlider *seekSlider;
	QSlider *volumeSlider;
	void saveWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::WidgetMedia *ui;

private slots:
	void on_toolButtonMediaPlaylistTaskHeader_clicked();
 void on_splitterMedia_customContextMenuRequested(QPoint pos);
 void on_actionMediaShuffle_triggered(bool checked);
 void on_actionMediaRepeat_triggered(bool checked);
	void skinChangeEvent();
};

#endif // WIDGETMEDIA_H
