//////////////////////////////////////////////////////////////////////////
//
// pgAdmin III - PostgreSQL Tools
// RCS-ID:      $Id$
// Copyright (C) 2002 - 2009, The pgAdmin Development Team
// This software is released under the Artistic Licence
//
// gqbDatabase.h - Database object for GQB.
//
//////////////////////////////////////////////////////////////////////////

#ifndef GQBDATABASE_H
#define GQBDATABASE_H

// App headers
#include "gqb/gqbObject.h"
#include "gqb/gqbSchema.h"
#include "gqb/gqbBrowser.h"

class gqbDatabase : public gqbObject
{
public:
    gqbDatabase(wxString name, type_gqbObject type);
    void createObjects(gqbBrowser *_tablesBrowser,  pgConn *_conn);

private:
    pgConn *conn;
    enum typeSchema
    {
        GQB_CATALOG,
        GQB_OTHER
    };
    void createSchemas(pgConn *conn,  gqbBrowser *tablesBrowser, wxTreeItemId parentNode,typeSchema MetaType, int indexImage);
};
#endif