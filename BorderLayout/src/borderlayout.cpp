#include "borderlayout.h"
#include <iostream>

BorderLayout::BorderLayout(QWidget *parent, int margin, int spacing):
    QLayout(parent)
{
    setMargin(margin);
    setSpacing(spacing);
}

BorderLayout::BorderLayout(int spacing) {
    setSpacing(spacing);
}

BorderLayout::~BorderLayout()
{
    QLayoutItem *l;
    while ((l = takeAt(0)))
        delete l;
}

void BorderLayout::addItem(QLayoutItem *item) {
    add(item, West);
}

void BorderLayout::addWidget(QWidget *widget, Position position) {
    add(new QWidgetItem(widget), position);
}

Qt::Orientations BorderLayout::expandingDirections() const {
    return Qt::Horizontal | Qt::Vertical;
}

bool BorderLayout::hasHeightForWidth() const {
    return false;
}

int BorderLayout::count() const {
    std::cout << "count()" << std::endl;
    return list.size();
}

QLayoutItem *BorderLayout::itemAt(int index) const {
    std::cout << "itemAt(): " << index << std::endl;
    ItemWrapper *wrapper = list.value(index);
    if (wrapper)
        return wrapper->item;
    else
        return 0;
}

QSize BorderLayout::minimumSize() const {
    return calculateSize(MinimumSize);
}

std::ostream& operator << (std::ostream& ostr, const QRect& rect) {
    ostr << rect.x() << " " << rect.y() << " " << rect.width() << " " << rect.height();
    return ostr;
}

void BorderLayout::setGeometry(const QRect &rect) {
    ItemWrapper *center = 0;
    int eastWidth = 0;
    int westWidth = 0;
    int northHeight = 0;
    int southHeight = 0;
    int centerHeight = 0;

    std::cout << "setGeometry: " << rect << std::endl;
    QLayout::setGeometry(rect);

    for (int i = 0; i < list.size(); ++i) {
        ItemWrapper *wrapper = list.at(i);
        QLayoutItem *item = wrapper->item;
        Position position = wrapper->position;

        if (position == North) {
            item->setGeometry(QRect(rect.x(), northHeight, rect.width(), item->sizeHint().height()));

            northHeight += item->geometry().height() + spacing();
        }
        else if (position == South) {
            std::cout << "SouthItem->geometry(): " << item->geometry() << std::endl;
            //item->setGeometry(QRect(item->geometry().x(),
                        //item->geometry().y(), rect.width(),
                        //item->sizeHint().height()));
            QRect r1 = QRect(item->geometry().x(),
                        item->geometry().y(), rect.width(),
                        item->sizeHint().height());
            std::cout << "SouthItem->r1(): " << item->geometry() << std::endl;
            item->setGeometry(r1);

            southHeight += item->geometry().height() + spacing();

            QRect r2 = QRect(rect.x(),
                        rect.y() + rect.height() - southHeight + spacing(),
                        item->geometry().width(),
                        item->geometry().height());
            std::cout << "SouthItem->r2(): " << item->geometry() << std::endl;
            item->setGeometry(r2);
            //item->setGeometry(QRect(rect.x(),
                        //rect.y() + rect.height() - southHeight + spacing(),
                        //item->geometry().width(),
                        //item->geometry().height()));
            std::cout << "SouthItem->geometry2 (): " << item->geometry() << std::endl;
        }
        else if (position == Center) {
            center = wrapper;
        }
    }

    centerHeight = rect.height() - northHeight - southHeight;

    for (int i = 0; i < list.size(); ++i) {
        ItemWrapper *wrapper = list.at(i);
        QLayoutItem *item = wrapper->item;
        Position position = wrapper->position;

        if (position == West) {
            item->setGeometry(QRect(rect.x() + westWidth, northHeight,
                        item->sizeHint().width(), centerHeight));

            westWidth += item->geometry().width() + spacing();
        }
        else if (position == East) {
            item->setGeometry(QRect(item->geometry().x(), item->geometry().y(),
                        item->sizeHint().width(), centerHeight));

            eastWidth += item->geometry().width() + spacing();

            item->setGeometry(QRect(
                        rect.x() + rect.width() - eastWidth + spacing(),
                        northHeight, item->geometry().width(),
                        item->geometry().height()));
        }
    }

    if (center)
        center->item->setGeometry(QRect(westWidth, northHeight,
                    rect.width() - eastWidth - westWidth,
                    centerHeight));
}

QSize BorderLayout::sizeHint() const {
    return calculateSize(SizeHint);
}

QLayoutItem *BorderLayout::takeAt(int index) {
    std::cout << "takeAt(): " << index << std::endl;
    if (index >= 0 && index < list.size()) {
        ItemWrapper *layoutStruct = list.takeAt(index);
        return layoutStruct->item;
    }
    return 0;
}

void BorderLayout::add(QLayoutItem *item, Position position) {
    list.append(new ItemWrapper(item, position));
}

QSize BorderLayout::calculateSize(SizeType sizeType) const {
    QSize totalSize;

    for (int i = 0; i < list.size(); ++i) {
        ItemWrapper *wrapper = list.at(i);
        Position position = wrapper->position;
        QSize itemSize;

        if (sizeType == MinimumSize)
            itemSize = wrapper->item->minimumSize();
        else // (sizeType == SizeHint)
            itemSize = wrapper->item->sizeHint();

        if (position == North || position == South || position == Center)
            totalSize.rheight() += itemSize.height();

        if (position == West || position == East || position == Center)
            totalSize.rwidth() += itemSize.width();
    }
    if (sizeType == SizeHint) {
        std::cout << "sizeHint: " << totalSize.width() << " " << totalSize.height() << std::endl;
    }
    if (sizeType == MinimumSize) {
        std::cout << "miniSize: " << totalSize.width() << " " << totalSize.height() << std::endl;
    }
    return totalSize;
}
