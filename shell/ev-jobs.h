/* this file is part of evince, a gnome document viewer
 *
 *  Copyright (C) 2008 Carlos Garcia Campos <carlosgc@gnome.org>
 *  Copyright (C) 2005 Red Hat, Inc
 *
 * Evince is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Evince is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __EV_JOBS_H__
#define __EV_JOBS_H__

#include <gio/gio.h>
#include <gtk/gtk.h>

#include "ev-document.h"
#include "ev-selection.h"
#include "ev-window.h"

G_BEGIN_DECLS

typedef struct _EvJob EvJob;
typedef struct _EvJobClass EvJobClass;

typedef struct _EvJobRender EvJobRender;
typedef struct _EvJobRenderClass EvJobRenderClass;

typedef struct _EvJobThumbnail EvJobThumbnail;
typedef struct _EvJobThumbnailClass EvJobThumbnailClass;

typedef struct _EvJobLinks EvJobLinks;
typedef struct _EvJobLinksClass EvJobLinksClass;

typedef struct _EvJobAttachments EvJobAttachments;
typedef struct _EvJobAttachmentsClass EvJobAttachmentsClass;

typedef struct _EvJobFonts EvJobFonts;
typedef struct _EvJobFontsClass EvJobFontsClass;

typedef struct _EvJobLoad EvJobLoad;
typedef struct _EvJobLoadClass EvJobLoadClass;

typedef struct _EvJobSave EvJobSave;
typedef struct _EvJobSaveClass EvJobSaveClass;

typedef struct _EvJobPrint EvJobPrint;
typedef struct _EvJobPrintClass EvJobPrintClass;

typedef struct _EvJobFind EvJobFind;
typedef struct _EvJobFindClass EvJobFindClass;

typedef struct _EvJobLayers EvJobLayers;
typedef struct _EvJobLayersClass EvJobLayersClass;

#define EV_TYPE_JOB		     	     (ev_job_get_type())
#define EV_JOB(object)		             (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB, EvJob))
#define EV_JOB_CLASS(klass)	             (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB, EvJobClass))
#define EV_IS_JOB(object)		     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB))
#define EV_JOB_GET_CLASS(object)             (G_TYPE_INSTANCE_GET_CLASS((object), EV_TYPE_JOB, EvJobClass))

#define EV_TYPE_JOB_LINKS		     (ev_job_links_get_type())
#define EV_JOB_LINKS(object)		     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_LINKS, EvJobLinks))
#define EV_JOB_LINKS_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_LINKS, EvJobLinksClass))
#define EV_IS_JOB_LINKS(object)		     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_LINKS))

#define EV_TYPE_JOB_ATTACHMENTS		     (ev_job_attachments_get_type())
#define EV_JOB_ATTACHMENTS(object)	     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_ATTACHMENTS, EvJobAttachments))
#define EV_JOB_ATTACHMENTS_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_ATTACHMENTS, EvJobAttachmentsClass))
#define EV_IS_JOB_ATTACHMENTS(object)	     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_ATTACHMENTS))

#define EV_TYPE_JOB_RENDER		     (ev_job_render_get_type())
#define EV_JOB_RENDER(object)		     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_RENDER, EvJobRender))
#define EV_JOB_RENDER_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_RENDER, EvJobRenderClass))
#define EV_IS_JOB_RENDER(object)	     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_RENDER))

#define EV_TYPE_JOB_THUMBNAIL		     (ev_job_thumbnail_get_type())
#define EV_JOB_THUMBNAIL(object)	     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_THUMBNAIL, EvJobThumbnail))
#define EV_JOB_THUMBNAIL_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_THUMBNAIL, EvJobThumbnailClass))
#define EV_IS_JOB_THUMBNAIL(object)	     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_THUMBNAIL))

#define EV_TYPE_JOB_FONTS		     (ev_job_fonts_get_type())
#define EV_JOB_FONTS(object)	     	     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_FONTS, EvJobFonts))
#define EV_JOB_FONTS_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_FONTS, EvJobFontsClass))
#define EV_IS_JOB_FONTS(object)		     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_FONTS))

#define EV_TYPE_JOB_LOAD		     (ev_job_load_get_type())
#define EV_JOB_LOAD(object)	     	     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_LOAD, EvJobLoad))
#define EV_JOB_LOAD_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_LOAD, EvJobLoadClass))
#define EV_IS_JOB_LOAD(object)		     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_LOAD))

#define EV_TYPE_JOB_SAVE		     (ev_job_save_get_type())
#define EV_JOB_SAVE(object)	     	     (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_SAVE, EvJobSave))
#define EV_JOB_SAVE_CLASS(klass)	     (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_SAVE, EvJobSaveClass))
#define EV_IS_JOB_SAVE(object)		     (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_SAVE))

#define EV_TYPE_JOB_PRINT                    (ev_job_print_get_type())
#define EV_JOB_PRINT(object)                 (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_PRINT, EvJobPrint))
#define EV_JOB_PRINT_CLASS(klass)            (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_PRINT, EvJobPrintClass))
#define EV_IS_JOB_PRINT(object)              (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_PRINT))

#define EV_TYPE_JOB_FIND                     (ev_job_find_get_type())
#define EV_JOB_FIND(object)                  (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_FIND, EvJobFind))
#define EV_JOB_FIND_CLASS(klass)             (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_FIND, EvJobFindClass))
#define EV_IS_JOB_FIND(object)               (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_FIND))

#define EV_TYPE_JOB_LAYERS                   (ev_job_layers_get_type())
#define EV_JOB_LAYERS(object)                (G_TYPE_CHECK_INSTANCE_CAST((object), EV_TYPE_JOB_LAYERS, EvJobLayers))
#define EV_JOB_LAYERS_CLASS(klass)           (G_TYPE_CHECK_CLASS_CAST((klass), EV_TYPE_JOB_LAYERS, EvJobLayersClass))
#define EV_IS_JOB_LAYERS(object)             (G_TYPE_CHECK_INSTANCE_TYPE((object), EV_TYPE_JOB_LAYERS))

typedef enum {
	EV_JOB_RUN_THREAD,
	EV_JOB_RUN_MAIN_LOOP
} EvJobRunMode;

struct _EvJob
{
	GObject parent;
	
	EvDocument *document;

	EvJobRunMode run_mode;

	guint cancelled : 1;
	guint finished : 1;
	guint failed : 1;
	
	GError *error;
	GCancellable *cancellable;

	guint idle_finished_id;
	guint idle_cancelled_id;
};

struct _EvJobClass
{
	GObjectClass parent_class;

	gboolean (*run)         (EvJob *job);
	
	/* Signals */
	void     (* cancelled)  (EvJob *job);
	void     (* finished)   (EvJob *job);
};

struct _EvJobLinks
{
	EvJob parent;

	GtkTreeModel *model;
};

struct _EvJobLinksClass
{
	EvJobClass parent_class;
};

struct _EvJobAttachments
{
	EvJob parent;

	GList *attachments;
};

struct _EvJobAttachmentsClass
{
	EvJobClass parent_class;
};

typedef enum {
	EV_RENDER_INCLUDE_NONE      = 0,
	EV_RENDER_INCLUDE_LINKS     = 1 << 0,
	EV_RENDER_INCLUDE_TEXT      = 1 << 1,
	EV_RENDER_INCLUDE_SELECTION = 1 << 2,
	EV_RENDER_INCLUDE_IMAGES    = 1 << 3,
	EV_RENDER_INCLUDE_FORMS     = 1 << 4,
	EV_RENDER_INCLUDE_ALL       = (1 << 5) - 1
} EvRenderFlags;

struct _EvJobRender
{
	EvJob parent;

	gint page;
	gint rotation;
	gdouble scale;

	EvPage *ev_page;
	gboolean page_ready;
	gint target_width;
	gint target_height;
	cairo_surface_t *surface;

	GList *link_mapping;
	GdkRegion *text_mapping;
	GList *image_mapping;
	GList *form_field_mapping;

	cairo_surface_t *selection;
	GdkRegion *selection_region;
	EvRectangle selection_points;
	EvSelectionStyle selection_style;
	GdkColor base;
	GdkColor text; 

	EvRenderFlags flags;
};

struct _EvJobRenderClass
{
	EvJobClass parent_class;

	void    (* page_ready) (EvJobRender *job);
};

struct _EvJobThumbnail
{
	EvJob parent;

	gint page;
	gint rotation;
	gdouble scale;
	
	GdkPixbuf *thumbnail;
};

struct _EvJobThumbnailClass
{
	EvJobClass parent_class;
};

struct _EvJobFonts
{
	EvJob parent;
	gboolean scan_completed;
};

struct _EvJobFontsClass
{
        EvJobClass parent_class;

	/* Signals */
	void (* updated)  (EvJobFonts *job,
			   gdouble     progress);
};

struct _EvJobLoad
{
	EvJob parent;
	
	EvLinkDest *dest;
	EvWindowRunMode mode;
	gchar *search_string;
	gchar *uri;
	gchar *password;
};

struct _EvJobLoadClass
{
	EvJobClass parent_class;
};

struct _EvJobSave
{
	EvJob parent;

	gchar *uri;
	gchar *document_uri;
};

struct _EvJobSaveClass
{
	EvJobClass parent_class;
};

struct _EvJobPrint
{
	EvJob parent;

	const gchar *format;
	gchar  *temp_file;
	EvPrintRange *ranges;
	gint n_ranges;
	EvPrintPageSet page_set;
	gint copies;
	gint pages_per_sheet;
	gboolean collate;
	gboolean reverse;
	gdouble width;
	gdouble height;
};

struct _EvJobPrintClass
{
	EvJobClass parent_class;
};

struct _EvJobFind
{
	EvJob parent;

	gint start_page;
	gint current_page;
	gint n_pages;
	GList **pages;
	gchar *text;
	gboolean case_sensitive;
	gboolean has_results;
};

struct _EvJobFindClass
{
	EvJobClass parent_class;

	/* Signals */
	void (* updated)  (EvJobFind *job,
			   gint       page);
};

struct _EvJobLayers
{
	EvJob parent;

	GtkTreeModel *model;
};

struct _EvJobLayersClass
{
	EvJobClass parent_class;
};

/* Base job class */
GType           ev_job_get_type           (void) G_GNUC_CONST;
gboolean        ev_job_run                (EvJob          *job);
void            ev_job_cancel             (EvJob          *job);
void            ev_job_failed             (EvJob          *job,
					   GQuark          domain,
					   gint            code,
					   const gchar    *format,
					   ...);
void            ev_job_failed_from_error  (EvJob          *job,
					   GError         *error);
void            ev_job_succeeded          (EvJob          *job);
gboolean        ev_job_is_cancelled       (EvJob          *job);
gboolean        ev_job_is_finished        (EvJob          *job);
gboolean        ev_job_is_failed          (EvJob          *job);
EvJobRunMode    ev_job_get_run_mode       (EvJob          *job);
void            ev_job_set_run_mode       (EvJob          *job,
					   EvJobRunMode    run_mode);

/* EvJobLinks */
GType           ev_job_links_get_type     (void) G_GNUC_CONST;
EvJob          *ev_job_links_new          (EvDocument     *document);

/* EvJobAttachments */
GType           ev_job_attachments_get_type (void) G_GNUC_CONST;
EvJob          *ev_job_attachments_new      (EvDocument     *document);

/* EvJobRender */
GType           ev_job_render_get_type    (void) G_GNUC_CONST;
EvJob          *ev_job_render_new         (EvDocument      *document,
					   gint             page,
					   gint             rotation,
					   gdouble          scale,
					   gint             width,
					   gint             height,
					   EvRenderFlags    flags);
void     ev_job_render_set_selection_info (EvJobRender     *job,
					   EvRectangle     *selection_points,
					   EvSelectionStyle selection_style,
					   GdkColor        *text,
					   GdkColor        *base);
/* EvJobThumbnail */
GType           ev_job_thumbnail_get_type (void) G_GNUC_CONST;
EvJob          *ev_job_thumbnail_new      (EvDocument      *document,
					   gint             page,
					   gint             rotation,
					   gdouble          scale);
/* EvJobFonts */
GType 		ev_job_fonts_get_type 	  (void) G_GNUC_CONST;
EvJob 	       *ev_job_fonts_new 	  (EvDocument      *document);

/* EvJobLoad */
GType 		ev_job_load_get_type 	  (void) G_GNUC_CONST;
EvJob 	       *ev_job_load_new 	  (const gchar 	   *uri,
					   EvLinkDest      *dest,
					   EvWindowRunMode  mode,
					   const gchar     *search_string);
void            ev_job_load_set_uri       (EvJobLoad       *load,
					   const gchar     *uri);
void            ev_job_load_set_password  (EvJobLoad       *job,
					   const gchar     *password);

/* EvJobSave */
GType           ev_job_save_get_type      (void) G_GNUC_CONST;
EvJob          *ev_job_save_new           (EvDocument      *document,
					   const gchar     *uri,
					   const gchar     *document_uri);

/* EvJobPrint */
GType           ev_job_print_get_type     (void) G_GNUC_CONST;
EvJob          *ev_job_print_new          (EvDocument      *document,
					   const gchar     *format,
					   gdouble          width,
					   gdouble          height,
					   EvPrintRange    *ranges,
					   gint             n_ranges,
					   EvPrintPageSet   page_set,
					   gint             pages_per_sheet,
					   gint             copies,
					   gdouble          collate,
					   gdouble          reverse);
/* EvJobFind */
GType           ev_job_find_get_type      (void) G_GNUC_CONST;
EvJob          *ev_job_find_new           (EvDocument      *document,
					   gint             start_page,
					   gint             n_pages,
					   const gchar     *text,
					   gboolean         case_sensitive);
gint            ev_job_find_get_n_results (EvJobFind       *job,
					   gint             pages);
gdouble         ev_job_find_get_progress  (EvJobFind       *job);
gboolean        ev_job_find_has_results   (EvJobFind       *job);
GList         **ev_job_find_get_results   (EvJobFind       *job);

/* EvJobLayers */
GType           ev_job_layers_get_type    (void) G_GNUC_CONST;
EvJob          *ev_job_layers_new         (EvDocument     *document);

G_END_DECLS

#endif /* __EV_JOBS_H__ */
