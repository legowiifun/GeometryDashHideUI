#include "hidableNode.hpp"

// if the node is having its visibility set, check a couple things first
	void hidableNode::setVisible(bool visible) {
		if (isHidden && m_fields->isUI) {
			CCNode::setVisible(false);
		}
		else {
			if (visible) {
				m_fields->hideNode = 1;
			}
			else {
				m_fields->hideNode = 2;
			}
			CCNode::setVisible(visible);

		}
	}