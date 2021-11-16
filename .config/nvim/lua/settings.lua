local opt = vim.opt
local cmd = vim.cmd
local api = vim.api

opt.background = "dark"
cmd [[colorscheme onedark]]
opt.clipboard = "unnamedplus"
opt.colorcolumn = "80"
opt.encoding = "utf-8"
opt.ignorecase = true
opt.incsearch = true
opt.smartcase = true
opt.number = true
opt.relativenumber = true
opt.showmode = false
opt.signcolumn = "yes"
opt.smartindent = true
opt.spelllang = "en"
opt.syntax = "true"
opt.tabstop = 4
opt.softtabstop = 4
opt.shiftwidth = 4
opt.smarttab = true
opt.expandtab = true
opt.termguicolors = true
opt.mouse = 'a'
opt.updatetime = 250
opt.wrap = false
api.nvim_command('au TextYankPost * silent! lua vim.highlight.on_yank {on_visual=false, timeout=150}')
opt.lazyredraw = true
