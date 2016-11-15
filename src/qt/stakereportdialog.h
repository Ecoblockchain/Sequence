// Copyright (c) 2015-2016 Silk Network Developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
// Original coding by Remy5

#ifndef SILK_STAKE_REPORT_DIALOG_H
#define SILK_STAKE_REPORT_DIALOG_H

#include "amount.h"

#include <QDialog>

namespace Ui {
class StakeReportDialog;
}

class WalletModel;

class StakeReportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StakeReportDialog(QWidget *parent = 0);
    ~StakeReportDialog();

    void setModel(WalletModel *model);
    void showEvent(QShowEvent* event);

private:
    Ui::StakeReportDialog *ui;
    WalletModel *ex_model;

    qint64 nLastReportUpdate;
    bool disablereportupdate;
    bool alreadyConnected;

    void updateStakeReport(bool fImmediate);

private slots:
    void updateStakeReportTimer();

public slots:
    void updateStakeReportbalanceChanged(CAmount, CAmount, CAmount, CAmount, CAmount, CAmount, CAmount, CAmount, CAmount);
    void updateStakeReportNow();
    void updateDisplayUnit(int);
    void CopyAllToClipboard();
};

#endif // SILK_STAKE_REPORT_DIALOG_H
