#ifndef PITCHDETECTOR_H
#define PITCHDETECTOR_H

#include <QObject>
#include <QAudioInput>
#include <QUrl>
#include <memory>

#include "pitchbuffer.h"
#include "pitch.h"

#define SAMPLE_RATE 48000

class PitchDetector : public QObject
{
	Q_OBJECT
	Q_PROPERTY(bool active MEMBER m_active WRITE setActive NOTIFY activeChanged)
	Q_PROPERTY(Pitch currentPitch MEMBER m_currentPitch NOTIFY samplesAnalyzed())
	Q_PROPERTY(Pitch confidentPitch MEMBER m_lastConfidentPitch NOTIFY samplesAnalyzed())
public:
	explicit PitchDetector(QObject *parent = nullptr);
	~PitchDetector();

	void setActive(bool active);
	bool m_active;
signals:
	void activeChanged();
	void samplesAnalyzed();
public slots:
private:
	QAudioInput *m_rec;
	QAudioFormat m_format;
	PitchBuffer m_dev;
	aubio_pitch_t *m_aubioPitch;
	fvec_t *m_aubioIn;
	fvec_t *m_aubioOut;
	Pitch m_currentPitch;
	Pitch m_lastConfidentPitch;
	float m_confidenceThreshold = .75;
private slots:
	void analyzeSamples();
};

#endif // PITCHDETECTOR_H