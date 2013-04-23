// Copyright 2013 Johann Duscher (a.k.a. Jonny Dee). All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
//    1. Redistributions of source code must retain the above copyright notice, this list of
//       conditions and the following disclaimer.
//
//    2. Redistributions in binary form must reproduce the above copyright notice, this list
//       of conditions and the following disclaimer in the documentation and/or other materials
//       provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY JOHANN DUSCHER ''AS IS'' AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
// FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
// ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// The views and conclusions contained in the software and documentation are those of the
// authors and should not be interpreted as representing official policies, either expressed
// or implied, of Johann Duscher.

#include "Presenter.hpp"
#include "Model.hpp"
#include "IView.hpp"

#include <QDebug>


Presenter::Presenter(Model& model, IView* view, QObject *parent) :
    QObject(parent),
    m_model(&model),
    m_view(view)
{
    m_view->setPresenter(*this);
    QObject::connect(m_model, &Model::textChanged, this, &Presenter::on_model_textChanged);
}

Presenter::~Presenter()
{
    delete m_view;
}

void Presenter::showView()
{
    m_view->setText(m_model->text());
    m_view->show();
}

void Presenter::on_model_textChanged()
{
    qDebug() << Q_FUNC_INFO;
    m_view->setText(m_model->text());
}

void Presenter::on_view_textChanged()
{
    qDebug() << Q_FUNC_INFO;
    m_model->setText(m_view->text());
}

void Presenter::on_view_quitButtonClicked()
{
    qDebug() << Q_FUNC_INFO;
    QMetaObject::invokeMethod(parent(), "quit");
}
