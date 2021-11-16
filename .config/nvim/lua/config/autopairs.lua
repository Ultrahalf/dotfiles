local present, pairs = pcall(require, 'nvim-autopairs')
if not present then
   error("Error loading nvim-autopair" .. "\n\n" .. err) -- not loaded
end

pairs.setup({
	disable_filetype = { "TelescopePrompt" , "vim" },
	map_cr = true,
	check_ts = true
})

