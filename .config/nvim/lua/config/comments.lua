local present, comment = pcall(require, 'kommentary.config')
if not present then
   error("Error loading kommentary" .. "\n\n" .. err) -- not loaded
end

comment.configure_language("default", {
	-- prefer_single_line_comments = true,
    prefer_multi_line_comments = true,
	use_consistent_indentation = true,
	ignore_whitespace = true,
})

