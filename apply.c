struct gitdiff_data {
	struct strbuf *root;
	int linenr;
	int p_value;
};

static char *find_name_gnu(struct strbuf *root,
	 * https://public-inbox.org/git/7vll0wvb2a.fsf@assigned-by-dhcp.cox.net/
	if (root->len)
		strbuf_insert(&name, 0, root->buf, root->len);
static char *find_name_common(struct strbuf *root,
	if (root->len) {
		char *ret = xstrfmt("%s%.*s", root->buf, len, start);
static char *find_name(struct strbuf *root,
		char *name = find_name_gnu(root, line, p_value);
	return find_name_common(root, line, def, p_value, NULL, terminate);
static char *find_name_traditional(struct strbuf *root,
		char *name = find_name_gnu(root, line, p_value);
		return find_name_common(root, line, def, p_value, NULL, TERM_TAB);
	return find_name_common(root, line, def, p_value, line + len, 0);
	name = find_name_traditional(&state->root, nameline, NULL, 0);
		name = find_name_traditional(&state->root, second, NULL, state->p_value);
		name = find_name_traditional(&state->root, first, NULL, state->p_value);
		first_name = find_name_traditional(&state->root, first, NULL, state->p_value);
		name = find_name_traditional(&state->root, second, first_name, state->p_value);
static int gitdiff_hdrend(struct gitdiff_data *state,
static int gitdiff_verify_name(struct gitdiff_data *state,
		*name = find_name(state->root, line, NULL, state->p_value, TERM_TAB);
		another = find_name(state->root, line, NULL, state->p_value, TERM_TAB);
static int gitdiff_oldname(struct gitdiff_data *state,
static int gitdiff_newname(struct gitdiff_data *state,
static int gitdiff_oldmode(struct gitdiff_data *state,
static int gitdiff_newmode(struct gitdiff_data *state,
static int gitdiff_delete(struct gitdiff_data *state,
static int gitdiff_newfile(struct gitdiff_data *state,
static int gitdiff_copysrc(struct gitdiff_data *state,
	patch->old_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_copydst(struct gitdiff_data *state,
	patch->new_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_renamesrc(struct gitdiff_data *state,
	patch->old_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_renamedst(struct gitdiff_data *state,
	patch->new_name = find_name(state->root, line, NULL, state->p_value ? state->p_value - 1 : 0, 0);
static int gitdiff_similarity(struct gitdiff_data *state,
static int gitdiff_dissimilarity(struct gitdiff_data *state,
static int gitdiff_index(struct gitdiff_data *state,
static int gitdiff_unrecognized(struct gitdiff_data *state,
static const char *skip_tree_prefix(int p_value,
	if (!p_value)
	nslash = p_value;
static char *git_header_name(int p_value,
		cp = skip_tree_prefix(p_value, first.buf, first.len);
			cp = skip_tree_prefix(p_value, sp.buf, sp.len);
		cp = skip_tree_prefix(p_value, second, line + llen - second);
	name = skip_tree_prefix(p_value, line, llen);
			np = skip_tree_prefix(p_value, sp.buf, sp.len);
			second = skip_tree_prefix(p_value, name + len + 1,
static int check_header_line(int linenr, struct patch *patch)
			     patch->extension_linenr, linenr);
		patch->extension_linenr = linenr;
int parse_git_diff_header(struct strbuf *root,
			  int *linenr,
			  int p_value,
			  const char *line,
			  int len,
			  unsigned int size,
			  struct patch *patch)
	struct gitdiff_data parse_hdr_state;
	patch->def_name = git_header_name(p_value, line, len);
	if (patch->def_name && root->len) {
		char *s = xstrfmt("%s%s", root->buf, patch->def_name);
	(*linenr)++;
	parse_hdr_state.root = root;
	parse_hdr_state.linenr = *linenr;
	parse_hdr_state.p_value = p_value;

	for (offset = len ; size > 0 ; offset += len, size -= len, line += len, (*linenr)++) {
			int (*fn)(struct gitdiff_data *, const char *, struct patch *);
			res = p->fn(&parse_hdr_state, line + oplen, patch);
			if (check_header_line(*linenr, patch))
			int git_hdr_len = parse_git_diff_header(&state->root, &state->linenr,
								state->p_value, line, len,
								size, patch);
	/*
	 * When running with --allow-overlap, it is possible that a hunk is
	 * seen that pretends to start at the beginning (but no longer does),
	 * and that *still* needs to match the end. So trust `match_end` more
	 * than `match_beginning`.
	 */
	if (state->allow_overlap && match_beginning && match_end &&
	    img->nr - preimage->nr != 0)
		match_beginning = 0;

			fill_stat_cache_info(state->repo->index, ce, &st);