require'lualine'.setup {
	options = {
		icons_enabled = true,
		theme = 'onedark',
		component_separators = {'', ''},
		section_separators = {'', ''},
		disabled_filetypes = { "NvimTree"},
	},
	sections = {
		lualine_a = {'mode'},
		lualine_b = {'branch'},
		lualine_c = {'filename'},
		lualine_x = {{'diagnostics', sources={'nvim_lsp'}},'encoding', 'fileformat'},
		lualine_y = {'filetype'},
		lualine_z = {'location'}
	},
	inactive_sections = {
		lualine_a = {},
		lualine_b = {},
		lualine_c = {'filename'},
		lualine_x = {'location'},
		lualine_y = {},
		lualine_z = {}
	},
	tabline = {},
	extensions = {},
}
