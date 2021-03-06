/*
 * Copyright © 2016 Red Hat, Inc
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors:
 *       Jan Grulich <jgrulich@redhat.com>
 */

#ifndef XDG_DESKTOP_PORTAL_KDE_APPCHOOSER_H
#define XDG_DESKTOP_PORTAL_KDE_APPCHOOSER_H

#include <QObject>
#include <QDBusObjectPath>

class AppChooser : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.freedesktop.impl.portal.AppChooser")
public:
    AppChooser(QObject *parent = 0);
    ~AppChooser();

public Q_SLOTS:
    uint chooseApplication(const QDBusObjectPath &handle,
                           const QString &app_id,
                           const QString &parent_window,
                           const QStringList &choices,
                           const QVariantMap &options,
                           QVariantMap &results);
};

#endif // XDG_DESKTOP_PORTAL_KDE_APPCHOOSER_H

