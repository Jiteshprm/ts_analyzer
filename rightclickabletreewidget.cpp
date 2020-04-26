#include "rightclickabletreewidget.h"
#include <QMouseEvent>
#include <QDebug>

RightClickableTreeWidget::RightClickableTreeWidget(QWidget* parent)
    : QTreeWidget(parent)
{
    right_click_item = NULL;
}

void RightClickableTreeWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() != Qt::RightButton) {
        QTreeWidget::mousePressEvent(event);
        return;
    }

    QTreeWidgetItem* item = this->itemAt(event->pos());
    if (item) {
        right_click_item = item;
    }
}

void RightClickableTreeWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() != Qt::RightButton) {
        QTreeWidget::mouseReleaseEvent(event);
        return;
    }

    QTreeWidgetItem* item = this->itemAt(event->pos());
    if (item) {
        if (right_click_item == item) {
            QPoint m;
            m.setX(event->x());
            m.setY(event->y());
            emit item_right_clicked(item, m);
            right_click_item = NULL;
        }
    }
}
