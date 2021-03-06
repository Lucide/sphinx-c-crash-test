# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

from recommonmark.transform import AutoStructify

# from sphinx_markdown_parser.parser import MarkdownParser
# from sphinx_markdown_parser.transform import AutoStructify

# -- Project information -----------------------------------------------------

project = "test"

# The full version, including alpha/beta/rc tags
release = u"1.0.0"

# -- General configuration ---------------------------------------------------

source_suffix = {
    ".md": "markdown"
}

primary_domain = "c"
highlight_language = "c"
pygments_style = "friendly"

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named "sphinx.ext.*") or your custom
# ones.
extensions = [
    "breathe",
    "recommonmark"
]

# -- Breathe configuration ---------------------------------------------------

breathe_projects = {project: u"D:/Users/Nemo/Desktop/test/doc/xml"}
breathe_default_project = project
breathe_domain_by_extension = {
    "h": "c",
}
breathe_show_define_initializer = True

# Add any paths that contain templates here, relative to this directory.
# templates_path = ["_templates"]

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
# exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = "sphinx_rtd_theme"

# Theme options are theme-specific and customize the look and feel of a theme
# further.  For a list of options available for each theme, see the
# documentation.
#
# html_theme_options = {}

# The name for this set of Sphinx documents.
# "<project> v<release> documentation" by default.
#
# html_title = u"test vtest"

# A shorter title for the navigation bar.  Default is the same as html_title.
#
# html_short_title = None

# The name of an image file (relative to this directory) to place at the top
# of the sidebar.
#
# html_logo = None

# The name of an image file (relative to this directory) to use as a favicon of
# the docs.  This file should be a Windows icon file (.ico) being 16x16 or 32x32
# pixels large.
#
# html_favicon = None

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
#
# html_static_path = [u"D:/Users/Nemo/Desktop/test/doc/static"]


# Add any extra paths that contain custom files (such as robots.txt or
# .htaccess) here, relative to this directory. These files are copied
# directly to the root of the documentation.
#
# html_extra_path = []

# If not None, a "Last updated on:" timestamp is inserted at every page
# bottom, using the given strftime format.
# The empty string is equivalent to "%b %d, %Y".
#
# html_last_updated_fmt = None

# Custom sidebar templates, maps document names to template names.
#
# html_sidebars = {}

# Additional templates that should be rendered to pages, maps page names to
# template names.
#
# html_additional_pages = {}

# If false, no module index is generated.
#
# html_domain_indices = True

# If false, no index is generated.
#
# html_use_index = True

# If true, the index is split into individual pages for each letter.
#
# html_split_index = False

# If true, links to the reST sources are added to the pages.
#
# html_show_sourcelink = True

# If true, "Created using Sphinx" is shown in the HTML footer. Default is True.
#
# html_show_sphinx = True

# If true, "(C) Copyright ..." is shown in the HTML footer. Default is True.
#
# html_show_copyright = True

# If true, an OpenSearch description file will be output, and all pages will
# contain a <link> tag referring to it.  The value of this option must be the
# base URL from which the finished HTML is served.
#
# html_use_opensearch = ""

# This is the file name suffix for HTML files (e.g. ".xhtml").
# html_file_suffix = None

# Language to be used for generating the HTML full-text search index.
# Sphinx supports the following languages:
#   "da", "de", "en", "es", "fi", "fr", "hu", "it", "ja"
#   "nl", "no", "pt", "ro", "ru", "sv", "tr", "zh"
#
# html_search_language = "en"

# A dictionary with options for the search language support, empty by default.
# "ja" uses this config value.
# "zh" user can custom change `jieba` dictionary path.
#
# html_search_options = {"type": "default"}

# The name of a javascript file (relative to the configuration directory) that
# implements a search results scorer. If empty, the default will be used.
#
# html_search_scorer = "scorer.js"

# Output file base name for HTML help builder.
#
# htmlhelp_basename = "testdoc"


# -- Recommonmark AutoStructify configuration --------------------------------

def setup(app):
    app.add_config_value("markdown_parser_config", {
        "enable_auto_toc_tree": False
    }, True)
    app.add_transform(AutoStructify)

# from pymdownx import emoji
#
# def setup(app):
#     app.add_source_parser(MarkdownParser)
#     app.add_config_value("markdown_parser_config", {
#         "auto_toc_tree_section": "Content",
#         "enable_auto_toc_tree": True,
#         "enable_eval_rst": True,
#         "extensions": [
#             "markdown.extensions.tables",
#             "pymdownx.magiclink",
#             "pymdownx.betterem",
#             "pymdownx.tilde",
#             "pymdownx.emoji",
#             "pymdownx.tasklist",
#             "pymdownx.superfences",
#             "pymdownx.saneheaders",
#             "pymdownx.escapeall"
#         ]
#     }, True)
#     app.add_transform(AutoStructify)
