import QtQuick 2.10
import QtQuick.Window 2.10
import QtQuick.Controls 2.2

import Fluid.Controls 1.0

import PitchDetector 1.0

ApplicationWindow {
	visible: true
	width: 640
	height: 480
	initialPage: Page {
		title: qsTr("Quick Pitch")
		Button {
			id: recordButton
			anchors.bottom: pitchLabel.top
			anchors.horizontalCenter: parent.horizontalCenter
			text: "Record"
			onClicked: pitchDetector.active = true;
		}
		HeadlineLabel {
			id: pitchLabel
			anchors.centerIn: parent
			text: "Frequency: " + pitchDetector.confidentPitch.frequency + " Hz\nConfidence: " + pitchDetector.confidentPitch.confidence + "\nNote name: " + pitchDetector.confidentPitch.noteLong + "\nAccuracy: " + pitchDetector.confidentPitch.accuracy
		}
		PitchDetector {
			id: pitchDetector
		}
	}
}
