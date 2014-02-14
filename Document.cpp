/***************************************************************************
 * 
 * Copyright (c) 2010 baimashi.com, Inc. All Rights Reserved
 * $Id$
 * 
 **************************************************************************/

/**
 * @file $HeadURL$
 * @author $Author$(hoping@baimashi.com)
 * @date $Date$
 * @version $Revision$
 * @brief 
 *  
 **/

#include "Document.h"

CDocument::CDocument()
{
	mpOutput = NULL;
}

void CDocument::parse(std::string aInput)
{
	reset();
	mpOutput = gumbo_parse(aInput.c_str());
}

CDocument::~CDocument()
{
	reset();
}

CSelection* CDocument::find(std::string aSelector)
{
	if (mpOutput == NULL)
	{
		throw "document not initialized";
	}

	CSelection* sel = new CSelection(mpOutput->root);
	return sel->find(aSelector);
}

void CDocument::reset()
{
	if (mpOutput != NULL)
	{
		gumbo_destroy_output(&kGumboDefaultOptions, mpOutput);
		mpOutput = NULL;
	}
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
