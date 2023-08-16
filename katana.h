#ifndef KATANA_H
#define KATANA_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QTabWidget>
//#include <QSyntaxHighlighter>
#include <QString>
#include <QMenu>
#include <QMessageBox>
#include <QErrorMessage>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QFileInfo>
//#include <QPrinter>
#include <QDockWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTreeView>
#include <QDirModel>
#include <QModelIndex>
#include <QToolBar>
#include <QTabBar>
#include <QAction>
#include <QToolButton>
#include <QCloseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QList>
#include <QUrl>
#include <QFont>
#include <QTextFormat>
#include <QTextCursor>
#include <QIODevice>
#include <QCloseEvent>                  // closeEvent
#include <QLabel>                       // GUI labels
#include <QActionGroup>
#include <QStandardPaths>

QT_BEGIN_NAMESPACE
namespace Ui { class katana; }
QT_END_NAMESPACE

class katana : public QMainWindow
{
    Q_OBJECT

public:
    katana(QWidget *parent = nullptr);
    ~katana();


private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionOpen_folder_triggered();

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

private:
    Ui::katana *ui;

};
#endif // KATANA_H
