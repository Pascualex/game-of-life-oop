#pragma once

#include "Engine/Agents/AgeCountingAgent.h"

class FireAgent : public AgeCountingAgent {
public:
	FireAgent(int x, int y);
	bool step() override;
	char get_icon() override;
	std::string get_type() override;
	Agent *clone() override;
	Agent *clone(int x, int y) override;
};