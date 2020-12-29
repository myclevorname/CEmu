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

#include "corewindow.h"
#include "dockwidget.h"
#include "settings.h"

#include <kddockwidgets/Config.h>

#include <QtCore/QCommandLineParser>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QStyleFactory>

int main(int argc, char **argv)
{
    KDDockWidgets::MainWindowOptions options = KDDockWidgets::MainWindowOption_None;
    const QString appName = QStringLiteral("CEmu");

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#endif

    QApplication app(argc, argv);
    Settings settings("./cemu");

    app.setOrganizationName(QStringLiteral("cemu-dev"));
    app.setApplicationName(appName);

    KDDockWidgets::Config::self().setFrameworkWidgetFactory(new DockWidgetFactory());
    KDDockWidgets::Config::self().setDockWidgetFactoryFunc(DockWidgetFactory::dockWidgetFactory);
    KDDockWidgets::Config::self().setSeparatorThickness(3);

    auto flags = KDDockWidgets::Config::self().flags();
    flags |= KDDockWidgets::Config::Flag_AlwaysTitleBarWhenFloating;
    flags |= KDDockWidgets::Config::Flag_TabsHaveCloseButton;
    KDDockWidgets::Config::self().setFlags(flags);

    CoreWindow window(appName, options);
    window.setWindowTitle(appName);
    window.show();

    return app.exec();
}
