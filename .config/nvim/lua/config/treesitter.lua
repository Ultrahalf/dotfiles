require'nvim-treesitter.configs'.setup {
	ensure_installed = "maintained", 
	autotag = {
		enable = true,
	},
	highlight = {
		enable = true,
		use_languagetree = true
	},
	indent = {
		enable = true
	},
	textobjects = {
		select = {
			enable = true,
			lookahead = true,
			keymaps = {
				["af"] = "@function.outer",
				["if"] = "@function.inner",
				["ac"] = "@class.outer",
				["ic"] = "@class.inner",
			},
		},
		swap = {
			enable = true,
			swap_next = {
				["<leader>sn"] = "@parameter.inner",
			},
			swap_previous = {
				["<leader>sp"] = "@parameter.inner",
			},
		},
		move = {
			enable = true,
			set_jumps = true,
			goto_next_start = {
				["[m"] = "@function.outer",
				["[c"] = "@class.outer",
			},
			goto_next_end = {
				["[M"] = "@function.outer",
				["[C"] = "@class.outer",
			},
			goto_previous_start = {
				["]m"] = "@function.outer",
				["]c"] = "@class.outer",
			},
			goto_previous_end = {
				["]M"] = "@function.outer",
				["]C"] = "@class.outer",
			},
		},
	},
}
