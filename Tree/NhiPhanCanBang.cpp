int chieuCao(Tree T){
	if(T==NULL) return 0;

	int hl = chieuCao(T->left);
	int hr = chieuCao(T->right);
	if(hl>hr)
		return hl+1;
	else return hr+1;
}