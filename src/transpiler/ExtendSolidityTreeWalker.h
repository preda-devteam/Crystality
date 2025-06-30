#pragma once
#include "antlr4-runtime.h"

class ExtendSolidityTreeWalker :
    public antlr4::tree::ParseTreeWalker
{
private:
	mutable bool m_bSkipCurrentRuleSubtree = false;
public:
	virtual ~ExtendSolidityTreeWalker() override;

	virtual void walk(antlr4::tree::ParseTreeListener* listener, antlr4::tree::ParseTree* t) const override;

	void SkipCurrentRuleSubtree() { m_bSkipCurrentRuleSubtree = true; }
};

