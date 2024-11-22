//#include "customproxymodel.h"

//CustomProxyModel::CustomProxyModel(QObject *parent)
//    : QSortFilterProxyModel{parent}
//    , current_column(0)
//{

//}

//bool CustomProxyModel::lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const
//{
//    if (source_left.data().toString() == source_right.data().toString())
//        return source_left.siblingAtColumn(priority).data().toString() < source_right.siblingAtColumn(priority).data().toString();

//   return source_left.data().toString() < source_right.data().toString();

////    return QSortFilterProxyModel::lessThan(source_left, source_right);
//}
