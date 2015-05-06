// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_UI_FILE_SELECTOR_H_INCLUDED
#define APP_UI_FILE_SELECTOR_H_INCLUDED
#pragma once

#include "base/unique_ptr.h"
#include "ui/window.h"

#include <string>

namespace ui {
  class Button;
  class ComboBox;
  class Entry;
}

namespace app {
  class CustomFileNameEntry;
  class FileList;
  class IFileItem;

  class FileSelector : public ui::Window {
  public:
    FileSelector();

    void goBack();
    void goForward();
    void goUp();
    void goInsideFolder();

    // Shows the dialog to select a file in the program.
    std::string show(const std::string& title,
      const std::string& initialPath,
      const std::string& showExtensions);

  private:
    void updateLocation();
    void updateNavigationButtons();
    void addInNavigationHistory(IFileItem* folder);
    void selectFileTypeFromFileName();
    void onGoBack();
    void onGoForward();
    void onGoUp();
    void onNewFolder();
    void onLocationCloseListBox();
    void onFileTypeChange();
    void onFileListFileSelected();
    void onFileListFileAccepted();
    void onFileListCurrentFolderChanged();

    ui::Button* m_goBack;
    ui::Button* m_goForward;
    ui::Button* m_goUp;
    ui::Button* m_newFolder;
    ui::ComboBox* m_location;
    ui::ComboBox* m_fileType;
    CustomFileNameEntry* m_fileName;
    FileList* m_fileList;

    // If true the navigation_history isn't
    // modified if the current folder changes
    // (used when the back/forward buttons
    // are pushed)
    bool m_navigationLocked;
  };

} // namespace app

#endif
