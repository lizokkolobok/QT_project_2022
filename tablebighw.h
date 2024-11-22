#ifndef TABLEBIGHW_H
#define TABLEBIGHW_H

#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QKeyEvent>
class tableBigHw : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit tableBigHw(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    void fillTableWithDataFromFile(QString path);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void saveTableWithDataToFile(QString path);
    QList<QList<QVariant>> tableData;
    void appendRow(const QList<QVariant> &row);
    void removeRow(int index);
private:

    QList<QString> headerList;

};

#endif // TABLEBIGHW_H
