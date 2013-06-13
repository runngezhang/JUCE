/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2013 - Raw Material Software Ltd.

   Permission is granted to use this software under the terms of either:
   a) the GPL v2 (or any later version)
   b) the Affero GPL v3

   Details of these licenses can be found at: www.gnu.org/licenses

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

   ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.juce.com for more information.

  ==============================================================================
*/

#ifndef __JUCER_RESOURCEEDITORPANEL_JUCEHEADER__
#define __JUCER_RESOURCEEDITORPANEL_JUCEHEADER__

#include "../model/jucer_JucerDocument.h"



//==============================================================================
/**
*/
class ResourceEditorPanel  : public Component,
                             private TableListBoxModel,
                             private ChangeListener,
                             private ButtonListener
{
public:
    //==============================================================================
    ResourceEditorPanel (JucerDocument& document);
    ~ResourceEditorPanel();

    void resized();
    void visibilityChanged();
    void changeListenerCallback (ChangeBroadcaster*);
    void buttonClicked (Button*);

    int getNumRows();
    void paintRowBackground (Graphics& g, int rowNumber, int width, int height, bool rowIsSelected);
    void paintCell (Graphics& g, int rowNumber, int columnId, int width, int height, bool rowIsSelected);
    Component* refreshComponentForCell (int rowNumber, int columnId, bool isRowSelected, Component* existingComponentToUpdate);
    int getColumnAutoSizeWidth (int columnId);
    void sortOrderChanged (int newSortColumnId, bool isForwards);
    void selectedRowsChanged (int lastRowSelected);

private:
    JucerDocument& document;
    TableListBox* listBox;
    TextButton* addButton;
    TextButton* reloadAllButton;
    TextButton* delButton;
};




#endif   // __JUCER_RESOURCEEDITORPANEL_JUCEHEADER__
