/*
 * FBReader -- electronic book reader
 * Copyright (C) 2005 Nikolay Pultsin <geometer@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <abstract/ZLFSManager.h>
#include <abstract/ZLInputStream.h>

#include "PdbPlugin.h"
#include "PdbReader.h"
//#include "PdbDescriptionReader.h"
//#include "PdbBookReader.h"
//#include "../../description/BookDescription.h"

bool PdbPlugin::acceptsFile(const std::string &extension) const {
	return (extension == "pdb") || (extension == "PDB");
}

bool PdbPlugin::readDescription(const std::string &path, BookDescription &description) const {
	PdbReader().readDocument(ZLFile(path).inputStream());
}

bool PdbPlugin::readModel(const BookDescription &description, BookModel &model) const {
	return false;
}

const std::string &PdbPlugin::iconName() const {
	static const std::string ICON_NAME = "FBReader/pdb";
	return ICON_NAME;
}
