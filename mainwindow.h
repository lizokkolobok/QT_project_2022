#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tablebighw.h"
#include "aboutus.h"
#include "addrowdialog.h"
#include <QTransposeProxyModel>
#include <QSortFilterProxyModel>
#include <QKeyEvent>
#include "customproxymodel.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    tableBigHw *tablebighw;
    size_t _shownDetailsColumn;
    aboutUs *_aboutus;
    //CustomProxyModel *proxyModel;
    QSortFilterProxyModel *proxyModel;
    AddRowDialog *_addrowdialog;
private slots:
    void loadFile();
    void saveFile();
    void on_tableView_clicked(const QModelIndex &index);
    void openInfo();
    void on_lineEdit_textEdited(const QString &arg1);
    void updateFilter(const QString & text);
    void on_comboBox_activated(int index);
    void addNewRowDialog();
    void deleteRow();
    void on_checkBoxRock_stateChanged(int arg1);
    void on_checkBoxPop_stateChanged(int arg1);
    void on_checkBoxHip_stateChanged(int arg1);
    void on_checkBoxDance_stateChanged(int arg1);
protected:
    virtual void keyPressEvent(QKeyEvent *event);

};
#endif // MAINWINDOW_H
