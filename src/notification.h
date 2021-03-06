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

#ifndef XDG_DESKTOP_PORTAL_KDE_NOTIFICATION_H
#define XDG_DESKTOP_PORTAL_KDE_NOTIFICATION_H

#include <QObject>
#include <QDBusObjectPath>

#include <KNotification>

class Notification : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.freedesktop.impl.portal.Notification")
public:
    Notification(QObject *parent = 0);
    ~Notification();

public Q_SLOTS:
    void addNotification(const QString &app_id,
                         const QString &id,
                         const QVariantMap &notification);
    void removeNotification(const QString &app_id,
                            const QString &id);
private Q_SLOTS:
    void notificationActivated(uint action);
    void notificationClosed();

private:
    QHash<QString, KNotification*> m_notifications;
};

#endif // XDG_DESKTOP_PORTAL_KDE_NOTIFICATION_H
