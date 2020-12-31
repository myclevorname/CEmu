/*
 * Copyright (c) 2015-2020 CE Programming.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STATEWIDGET_H
#define STATEWIDGET_H

#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
class QTableWidget;
class QTableWidgetItem;
QT_END_NAMESPACE

class StateWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StateWidget(QWidget *parent = nullptr);

private slots:
    void createState();

private:
    QString getStatePath(const QString &name) const;
    void addState(const QString &name, bool edit);
    void removeSelected();

    QTableWidget *mTbl;

    QPushButton *mBtnExportSelected;
    QPushButton *mBtnRestoreSelected;
    QPushButton *mBtnRemoveSelected;
};

#endif
