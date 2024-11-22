#include "mainwindow.h"
#include "aboutus.h"
#include "./ui_mainwindow.h"
#include "ui_aboutus.h"
#include <QFileDialog>
#include "customproxymodel.h"
#include <QRegularExpression>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);    
    tablebighw = new tableBigHw(this);
    ui->tableView->setModel(tablebighw);

    //ui->tableView->setModel();

    _aboutus = new aboutUs();
    _addrowdialog = new AddRowDialog();

    connect(ui->actionLOAD, SIGNAL(triggered()), this, SLOT(loadFile()));
    connect(ui->actionSAVE, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionLOGO, SIGNAL(triggered()), this, SLOT(openInfo()));
    connect(ui->tableView, SIGNAL(clicked()), this, SLOT(onTableClicked()));
    connect(ui->search, SIGNAL(textChanged(const QString &)), this, SLOT(updateFilter(const QString &)));
    connect(ui->addNewRowButton, SIGNAL(clicked()), this, SLOT(addNewRowDialog()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(deleteRow()));
    tablebighw = new tableBigHw(this);
    ui->tableView->setModel(tablebighw);
    proxyModel = new QSortFilterProxyModel(this);
    //CustomProxyModel* proxyModel = new CustomProxyModel(this);
    //proxyModel->priority = 4;

    proxyModel->setSourceModel(tablebighw);
    ui->tableView->setSortingEnabled(true);

    ui->tableView->setModel(proxyModel);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void MainWindow::loadFile()
{
//    delete tablebighw;
    //proxyModel = new CustomProxyModel(this);
//    proxyModel = new QSortFilterProxyModel(this);
//    tablebighw = new tableBigHw(this);
    QString fileName = QFileDialog::getOpenFileName(this, "Open File",
                                                    "../",
                                                    "Data (*.csv)");
    if (QString(fileName).isEmpty() == false)
    {
        delete tablebighw;
        proxyModel = new QSortFilterProxyModel(this);
        tablebighw = new tableBigHw(this);
        tablebighw->fillTableWithDataFromFile(fileName);
        proxyModel->setSourceModel(tablebighw);
        ui->tableView->setModel(proxyModel);
        ui->tableView->setSortingEnabled(true);
        //ui->tableView->setDynamicSortFilter(true);
        proxyModel->setFilterKeyColumn(4);
    }
//    proxyModel = new QSortFilterProxyModel(this);
//    tablebighw = new tableBigHw(this);
//    tablebighw->fillTableWithDataFromFile(fileName);
//    proxyModel->setSourceModel(tablebighw);
//    ui->tableView->setModel(proxyModel);
//    ui->tableView->setSortingEnabled(true);
//    proxyModel->setFilterKeyColumn(1);

}


void MainWindow::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open File", "../", "Data (*.csv)");
    tablebighw->saveTableWithDataToFile(fileName);
}


void MainWindow::openInfo()
{
   _aboutus->show();
}

void MainWindow::addNewRowDialog()
{
   //_addrowdialog->show();
   AddRowDialog d(this);
   //exec - function as show() but it also block interaction with either the whole app or parent widget
   if (d.exec() == QDialog::Accepted)
   {
       tablebighw->appendRow(d.NewRow());
   }
}

void MainWindow::deleteRow()
{

    QModelIndex index1 = ui->tableView->currentIndex();
    tablebighw->removeRow(index1.row());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//function which get index of row by click on any cell and then fill widget
//with details about song
void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    setFocusPolicy(Qt::StrongFocus);

    int row = index.row();
    int column = 0;
    QModelIndex songIndex = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData = tablebighw->data(songIndex);
    ui->artistData->setText(songData.toString());

    column = 1;
    QModelIndex songIndex1 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData1 = tablebighw->data(songIndex1);
    ui->songData->setText(songData1.toString());

    column = 2;
    QModelIndex songIndex2 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData2 = tablebighw->data(songIndex2);
    ui->durationData->setText(songData2.toString());

    column = 3;
    QModelIndex songIndex3 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData3 = tablebighw->data(songIndex3);
    ui->yearData->setText(songData3.toString());

    column = 4;
    QModelIndex songIndex4 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData4 = tablebighw->data(songIndex4);
    ui->popularityData->setText(songData4.toString());

    column = 10;
    QModelIndex songIndex5 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData5 = tablebighw->data(songIndex5);
    ui->genreData->setText(songData5.toString());

    column = 5;
    QModelIndex songIndex6 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData6 = tablebighw->data(songIndex6);
    ui->loudnessData->setText(songData6.toString());

    column = 9;
    QModelIndex songIndex7 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData7 = tablebighw->data(songIndex7);
    ui->tempoData->setText(songData7.toString());

    column = 6;
    QModelIndex songIndex8 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData8 = tablebighw->data(songIndex8);
    ui->speechinessData->setText(songData8.toString());

    column = 7;
    QModelIndex songIndex9 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData9 = tablebighw->data(songIndex9);
    ui->acousticnessData->setText(songData9.toString());

    column = 8;
    QModelIndex songIndex10 = proxyModel->mapToSource(proxyModel->index(row, column));
    QVariant songData10 = tablebighw->data(songIndex10);
    ui->instrumentalnessData->setText(songData10.toString());

}


void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

}

//function for filtering by search QLineEdit
//set filter by regular expression (empty string by default,
//so in this case it will accept all in source model) (compare itself with data and accept needed data)
void MainWindow::updateFilter(const QString & text)
{
    proxyModel->setSourceModel(tablebighw);
    ui->tableView->setModel(proxyModel);
    proxyModel->setFilterKeyColumn(1);
    proxyModel->setFilterRegularExpression(QRegularExpression(text));
}





//when ones choose filter in combobox (any row has its index) , this function sort by this parameter(column)
void MainWindow::on_comboBox_activated(int index)
{

    proxyModel->setSourceModel(tablebighw);
    ui->tableView->setModel(proxyModel);
    //int a = 8;
    if ( index == 0 )
    {
        proxyModel->sort(-1);
    }
    else if( index ==1 )
    {
        //a = 0;
       proxyModel->sort(3);
       proxyModel->sort(0);
    }
    else if ( index == 2 )
    {
        //a = 1;
       proxyModel->sort(3);
       proxyModel->sort(1);
    }
    else if ( index == 3 )
    {
        //a = 10;
       proxyModel->sort(3);
       proxyModel->sort(10);
    }
    else if ( index == 4 )
    {
        //a = 2;
       proxyModel->sort(3);
       proxyModel->sort(2);
    }
    else if ( index == 5 )
    {
        //a = 4;
       proxyModel->sort(3);
       proxyModel->sort(4);
    }

    //proxyModel->current_column = a;
   // proxyModel->sort(a);
}


//four functions for filter with check boxes
//update filterRegularExpression , so break it
//respect case sensitivity
void MainWindow::on_checkBoxRock_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        proxyModel->setSourceModel(tablebighw);
        ui->tableView->setModel(proxyModel);
        proxyModel->setFilterKeyColumn(10);
        proxyModel->setFilterRegularExpression("rock");
    }
    else if (arg1 == Qt::Unchecked)
    {
        ui->tableView->setModel(tablebighw);
        proxyModel->setSourceModel(tablebighw);
    }
}


void MainWindow::on_checkBoxPop_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        proxyModel->setSourceModel(tablebighw);
        ui->tableView->setModel(proxyModel);
        proxyModel->setFilterKeyColumn(10);
        proxyModel->setFilterRegularExpression("pop");
    }
    else if (arg1 == Qt::Unchecked)
    {
        ui->tableView->setModel(tablebighw);
        proxyModel->setSourceModel(tablebighw);
    }
}


void MainWindow::on_checkBoxHip_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        proxyModel->setSourceModel(tablebighw);
        ui->tableView->setModel(proxyModel);
        proxyModel->setFilterKeyColumn(10);
        proxyModel->setFilterRegularExpression("hip hop");
    }
    else if (arg1 == Qt::Unchecked)
    {
        ui->tableView->setModel(tablebighw);
        proxyModel->setSourceModel(tablebighw);
    }
}


void MainWindow::on_checkBoxDance_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        proxyModel->setSourceModel(tablebighw);
        ui->tableView->setModel(proxyModel);
        proxyModel->setFilterKeyColumn(10);
        proxyModel->setFilterRegularExpression("Dance/Electronic");
    }
    else if (arg1 == Qt::Unchecked)
    {
        ui->tableView->setModel(tablebighw);
        proxyModel->setSourceModel(tablebighw);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    setFocusPolicy(Qt::StrongFocus);
    QModelIndex index = ui->tableView->currentIndex();
    int column = index.column();
    int row = index.row();
    if ( event->key() == Qt::Key_Down)
    {
       ++row;
    }
    else if (event->key() == Qt::Key_Up)
    {
        --row;

    }
    index = tablebighw->index(row, column);
    on_tableView_clicked(index);
}

