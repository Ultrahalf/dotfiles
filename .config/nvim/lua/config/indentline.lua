vim.opt.list = true
vim.opt.listchars:append("space:⋅")

require("indent_blankline").setup {
    space_char_blankline = "⋅",
	--[[ show_first_indent_level = false, ]]
	buftype_exclude = {
		"help",
		"nofile",
		"terminal",
	},
	filetype_exclude = {
		"help",
		"packer",
		'NvimTree',
	},
	use_treesitter = true,
}

