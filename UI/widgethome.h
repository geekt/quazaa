#ifndef WIDGETHOME_H
#define WIDGETHOME_H

#include <QWidget>

namespace Ui {
    class WidgetHome;
}

class WidgetHome : public QWidget {
    Q_OBJECT
public:
    WidgetHome(QWidget *parent = 0);
    ~WidgetHome();
	void saveWidget();
	void mouseDoubleClickEvent(QMouseEvent *);

signals:
	void triggerLibrary();
	void triggerTransfers();
	void triggerSecurity();
	void requestSearch(QString *searchString);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::WidgetHome *ui;

private slots:
 void on_splitterHome_customContextMenuRequested(QPoint pos);
 void on_toolButtonWelcomeSearch_clicked();
 void on_labelWelcomeUserGuideLink_linkActivated(QString link);
 void on_labelWelcomeWizardLink_linkActivated(QString link);
 void on_labelWelcomeSkinLink_linkActivated(QString link);
 void on_labelWelcomeOpenTorrentLink_linkActivated(QString link);
 void on_labelWelcomeURLDownloadLink_linkActivated(QString link);
 void on_labelTorrentsTaskSeedTorrentLink_linkActivated(QString link);
 void on_labelLibraryTaskHashFaster_linkActivated(QString link);
 void skinChangeEvent();
};

#endif // WIDGETHOME_H
