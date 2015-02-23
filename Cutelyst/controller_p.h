/*
 * Copyright (C) 2014-2015 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef CONTROLLER_P_H
#define CONTROLLER_P_H

#include "controller.h"
#include "code.h"

namespace Cutelyst {

class ControllerPrivate
{
    Q_DECLARE_PUBLIC(Controller)
public:
    ControllerPrivate(Controller *parent);
    void init(Application *app, Dispatcher *_dispatcher);
    // Called when the Dispatcher has finished
    // setting up all controllers
    void setupFinished();
    Action* actionClass(const QVariantHash &args);
    Action* createAction(const QVariantHash &args, const QMetaMethod &method, Controller *controller, Application *app);
    void registerActionMethods(const QMetaObject *meta, Controller *controller, Application *app);
    QMap<QString, QString> parseAttributes(const QMetaMethod &method, const QByteArray &str, const QByteArray &name);
    QStack<Code *> gatherActionRoles(const QVariantHash &args);
    QString parsePathAttr(const QString &_value);
    QString parseChainedAttr(const QString &attr);

    QObject *instantiateClass(const QByteArray &name, const QByteArray &super);
    bool superIsClassName(const QMetaObject *super, const QByteArray &className);

    Controller *q_ptr;
    QString pathPrefix;
    Action *begin = 0;
    ActionList autoList;
    Action *end = 0;
    ActionList actionSteps;
    Dispatcher *dispatcher;
    bool parsedActions = false;
    QHash<QString, Action *> actions;
};

}

#endif // CONTROLLER_P_H
