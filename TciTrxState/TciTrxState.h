// Copyright (c) 2017 Expert Electronics
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef TCITRXSTATE_H
#define TCITRXSTATE_H

#include <QtCore>
#include <QColor>
#include <atomic>
#include <QtQml/qqmlregistration.h>

namespace ExpertElectronics {

class TciTrxState : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    explicit TciTrxState(QObject *parent = nullptr);

    Q_INVOKABLE void setTrxCount(quint32 value);
    Q_INVOKABLE quint32 trxCount() const;

    Q_INVOKABLE void setChannelsCount(quint32 value);
    Q_INVOKABLE quint32 channelsCount() const;

    Q_INVOKABLE void setVfoLimits(quint64 min, quint64 max);
    Q_INVOKABLE qint64 vfoMin() const;
    Q_INVOKABLE qint64 vfoMax() const;

    Q_INVOKABLE void setIfLimits(int min, int max);
    Q_INVOKABLE qint64 ifMin() const;
    Q_INVOKABLE qint64 ifMax() const;

    Q_INVOKABLE void setModulationsList(const QStringList &list);
    Q_INVOKABLE QStringList modulationsList() const;

    Q_INVOKABLE void setIqOutSampleRate(quint32 value);
    Q_INVOKABLE quint32 iqOutSampleRate() const;

    Q_INVOKABLE void setAudioSampleRate(quint32 value);
    Q_INVOKABLE quint32 audioSampleRate() const;

    Q_INVOKABLE void setAudioStart(quint32 trx, bool state);
    Q_INVOKABLE bool audioStart(quint32 trx) const;

    Q_INVOKABLE void setIqStart(quint32 trx, bool state);
    Q_INVOKABLE bool iqStart(quint32 trx) const;

    Q_INVOKABLE quint32 cwSpeed() const noexcept;
    Q_INVOKABLE quint32 cwMacrosDelay() const noexcept;

    Q_INVOKABLE bool ritEnable(quint32 trx) const;
    Q_INVOKABLE bool xitEnable(quint32 trx) const;
    Q_INVOKABLE bool splitEnable(quint32 trx) const;
    Q_INVOKABLE int ritOffset(quint32 trx) const;
    Q_INVOKABLE int xitOffset(quint32 trx) const;

    Q_INVOKABLE bool sqlEnable(quint32 trx) const;
    Q_INVOKABLE int sqlLevel(quint32 trx) const;

    Q_INVOKABLE bool channelEnable(quint32 trx, quint32 channel) const;
    Q_INVOKABLE bool rxFilter(quint32 trx, int &low, int &high);

    Q_INVOKABLE int volume() const;

public slots:
    void setRxEnable(quint32 trx, bool state);

    bool rxEnable(quint32 trx) const;

    void setTxEnable(quint32 trx, bool state);

    bool txEnable(quint32 trx) const;

    void start();

    void stop();

    bool isStart() const;

    void setPreamp(int value);

    int preamp() const;

    void setDdsFreq(quint32 trx, double freq);
    double ddsFreq(quint32 trx);

    void setIfFreq(quint32 trx, quint32 channel, double freq);
    double ifFreq(quint32 trx, quint32 channel);

    void setVfo(quint32 trx, quint32 channel, double freq);
    double vfo(quint32 trx, quint32 channel);

    void setTrx(quint32 trx, bool state);
    bool trx(quint32 trx);

    void setTune(quint32 trx, bool state);
    bool tune(quint32 trx);

    void setModulation(quint32 trx, const QString &mode);

    QString modulation(quint32 trx);

    void setMacros(quint32 trx, const QString &text);

    void setCwMacrosStop();

    void setCwSpeed(quint32 value);

    void setCwMacrosDelay(quint32 value);

    void setSpot(const QString &callsign,
                 const QString &mode,
                 quint64 freq,
                 const QColor &color,
                 const QString &text);

    void setDeleteSpot(const QString &callsign);

    void setRitEnable(quint32 trx, bool state);

    void setXitEnable(quint32 trx, bool state);

    void setSplitEnable(quint32 trx, bool state);

    void setRitOffset(quint32 trx, int value);

    void setXitOffset(quint32 trx, int value);

    void setSqlEnable(quint32 trx, bool state);

    void setSqlLevel(quint32 trx, int value);

    void setChannelEnable(quint32 trx, quint32 channel, bool state);

    void setRxFilter(quint32 trx, int low, int high);

    void setCwMessage(quint32 trx, const QString &before, const QString &callsign, const QString &after);

    void addCwMessageCallsign(const QString &callsign);

    void setInFocus();

    void setClearSpots();

    void setVolume(int value);

signals:
    void started();
    void stoped();

    void preampChanged(int value);

    void ddsFreqChanged(quint32 trx, double value);

    void ifFreqChanged(quint32 trx, quint32 channel, double value);

    void vfoChanged(quint32 trx, quint32 channel, double value);

    void trxChanged(quint32 trx, bool state);

    void tuneChanged(quint32 trx, bool state);

    void vfoLimitsChanged(quint64 min, quint64 max);

    void ifLimitsChanged(int min, int max);

    void modulationsListChanged(QStringList list);

    void modulationChanged(quint32 trx, QString mode);

    void iqOutSampleRateChanged(quint32 value);

    void audioSampleRateChanged(quint32 value);

    void iqStartChanged(quint32 trx, bool state);

    void audioStartChanged(quint32 trx, bool state);

    void rxEnableChanged(quint32 trx, bool state);

    void txEnableChanged(quint32 trx, bool state);

    void cwMacros(quint32 trx, QString text);

    void cwMakrosStop();

    void cwSpeedChanged(quint32 value);

    void cwMacrosDelayChanged(quint32 value);

    void spot(QString callsign, QString mode, quint64 freq, QColor color, QString text);
    void deleteSpot(QString callsign);

    void ritEnableChanged(quint32 trx, bool state);

    void xitEnableChanged(quint32 trx, bool state);

    void splitEnableChanged(quint32 trx, bool state);

    void ritOffsetChanged(quint32 trx, int value);

    void xitOffsetChanged(quint32 trx, int value);

    void sqlEnableChanged(quint32 trx, bool state);

    void sqlLevelChanged(quint32 trx, int value);

    void channelEnableChanged(quint32 trx, quint32 channel, bool state);

    void rxFilterChanged(quint32 trx, int low, int high);

    void cwMessage(quint32 trx, QString before, QString callsign, QString after);

    void cwMessageCallsign(const QString &callsign);

    void appInFocus();

    void clearSpots();

    void volumeChanged(int);

private:
    Q_DISABLE_COPY(TciTrxState)

private:
    quint32 m_trxCount;
    quint32 m_channelsCount;
    quint64 m_vfoMin;
    quint64 m_vfoMax;
    int     m_ifMin;
    int     m_ifMax;
    quint32 m_iqOutSampleRate;
    quint32 m_audioSampleRate;
    quint32 m_cwSpeed;
    quint32 m_cwDelay;
    QJsonObject m_state;
    QStringList m_mudulations;
    int     m_volume;
};

}  // namespace ExpertElectronics

#endif // TCITRXSTATE_H
