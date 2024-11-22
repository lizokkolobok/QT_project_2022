#include "tablebighw.h"
#include <QFile>
#include <QColor>
#include <QTextStream>
#include <QSortFilterProxyModel>
#include <QKeyEvent>
#include "./ui_mainwindow.h"

tableBigHw::tableBigHw(QObject *parent)
    : QAbstractTableModel(parent)
{

}



void tableBigHw::fillTableWithDataFromFile(QString path)
{
    QFile inputFile(path);
        inputFile.open(QFile::ReadOnly | QFile::Text);
        QTextStream inputStream(&inputFile);

        QString firstline = inputStream.readLine();
        for (QString& item : firstline.split(",")) {
            headerList.append(item);
        }

        while(!inputStream.atEnd())
        {
            QString line = inputStream.readLine();

            QList<QVariant> dataRow;
            QList<QString> a = line.split(",");
            for (int i = 0; i < a.length(); i++) {
                if (i == 2 || i == 3 || i == 4)
                {
                    dataRow.append(QVariant(a[i]).toInt());
                }
                else if ( i == 5 || i == 6 || i == 7 || i == 8 || i == 9)
                {
                    dataRow.append(QVariant(a[i]).toDouble());
                }
                else
                {
                dataRow.append(QVariant(a[i]));
                }
            }
            tableData.append(dataRow);
        }
        inputFile.close();

}


void tableBigHw::saveTableWithDataToFile(QString path)
{
    QFile outputFile(path);
        outputFile.open(QFile::WriteOnly | QFile::Text);
        QTextStream outputStream(&outputFile);

        bool first = true;
        for (QString& item : headerList) {
            if (first)
            {
                outputStream << item;
                first = false;
            }
            else
            {
                outputStream << ",";
                outputStream << item;
            }

        }
        outputStream << "\n";

        for (QList<QVariant>& row: tableData)
        {
            bool first = true;
            for (QVariant& item : row)
            {
                if (first)
                {
                    outputStream << item.toString();
                    first = false;
                }
                else
                {
                    outputStream << ",";
                    outputStream << item.toString();
                }
            }
            outputStream << "\n";
        }
        outputFile.close();
}


QVariant tableBigHw::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
      {
          return headerList[section];
      }
    else if (role == Qt::BackgroundColorRole)
            return QColor(Qt::black);
      return QVariant();
}

int tableBigHw::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return tableData.size();
}

int tableBigHw::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    if (tableData.empty())
        {
            return 0;
        }

        return tableData[0].size();
}

QVariant tableBigHw::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    int row = index.row();
    int column = index.column();
    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return tableData.at(row).at(column);
    }
    return QVariant();
 }

bool tableBigHw::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        int row = index.row();
        int col = index.column();
        tableData[row][col] = value.toString();
        //emit empty marcos (help to define slots)
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}


//responsible for if cell is selected
Qt::ItemFlags tableBigHw::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;

}


void tableBigHw::appendRow(const QList<QVariant> &row)
{
    size_t newRowNumber = rowCount();
    beginInsertRows(QModelIndex(), newRowNumber, newRowNumber);
    tableData.append(row);
    endInsertRows();
}

void tableBigHw::removeRow(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    tableData.removeAt(index);
    endRemoveRows();
}




