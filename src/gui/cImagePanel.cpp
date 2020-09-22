#include "cImagePanel.h"

wxBEGIN_EVENT_TABLE(cImagePanel, wxPanel)
    EVT_PAINT(cImagePanel::paintEvent)
    EVT_SIZE(cImagePanel::OnSize)
wxEND_EVENT_TABLE()
/**
 * @brief Basic constructor for loading image, for now..
 * @param parent
 * @param id
 * @param file
 * @param format
 */
cImagePanel::cImagePanel(wxWindow* parent, wxStandardID id, wxString file, wxBitmapType format) : wxPanel(parent, id)
{
    image.LoadFile(file, format);
    w = -1;
    h = -1;
}
/**
 * @brief wxPaintDC paint-event handler function
 * @param evt
 */
void cImagePanel::paintEvent(wxPaintEvent &evt)
{
    wxPaintDC dc(this);
    render(dc);
    evt.Skip();
}
/**
 * @brief wxClientDC paint-event handler function
 */
void cImagePanel::paintNow()
{
    wxClientDC dc(this);
    render(dc);
}
/**
 * @brief Rendering function for resize calculations
 * @param dc
 */
void cImagePanel::render(wxDC &dc) {
    int neww, newh;
    dc.GetSize(&neww, &newh);

    if (neww != w || newh != h) {
        resized = wxBitmap(image.Scale(neww, newh, wxIMAGE_QUALITY_HIGH));
        w = neww;
        h = newh;
    }
    dc.DrawBitmap(resized, 0, 0, false);
}
/**
 * @brief Handler function for resizing events
 * @param evt
 */
void cImagePanel::OnSize(wxSizeEvent &evt) {
    Refresh();
    evt.Skip();
}
