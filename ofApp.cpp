#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
	ofRotate(90);

	auto radius_min = 60;
	auto radius_max = 110;

	for (int i = 0; i < 3; i++) {

		for (int line = 0; line < 25; line++) {

			auto radius = ofRandom(radius_min, radius_max);
			auto start_deg = ofGetFrameNum() * 5 + ofRandom(720);
			auto len = ofRandom(60, 360);

			glm::vec2 point, prev_point, base_point;
			auto first = true;
			for (int deg = start_deg; deg < start_deg + len; deg += 1) {

				int position_deg = deg % 720;
				if (position_deg < 360) {

					point = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD)) + glm::vec2((radius_min + radius_max) * -0.5, (i - 1) * 240);
				}
				else {

					int tmp_radius = ofMap(radius, radius_min, radius_max, radius_max, radius_min);
					point = glm::vec2(-1 * tmp_radius * cos(deg * DEG_TO_RAD), tmp_radius * sin(deg * DEG_TO_RAD)) + glm::vec2((radius_min + radius_max) * 0.5, (i - 1) * 240);
				}

				if (!first) {

					ofSetColor(39, ofMap(deg, start_deg, start_deg + len, 64, 255));
					ofDrawLine(prev_point, point);
				}
				else {

					first = false;
				}
				prev_point = point;

			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}