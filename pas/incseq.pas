Const
		maxn=trunc(3e4) + 9;
Var
        f,a:array[0..maxn] of longint;
	k, n, i : longint;
function tknp(i: longint): longint;
var
        d, c, mid : longint;
begin
        d := 1; c := k;
	while d < c do
	begin
	        mid := (d + c) div 2;
                if a[f[mid]]>=a[i] then c:=mid else d:=mid+1
	end;
	exit(c);
end;
procedure process;
begin
        readln(n);
	for i := 1 to n do read(a[i]);
	f[1] := 1;
	k := 1;
	for i := 2 to n do
	if a[i] > a[f[k]] then
	begin
	        inc(k);
		f[k] := i;
	end else f[tknp(i)] := i;
	writeln(k);
end;
BEGIN
        assign(input,'incseq.inp');
        assign(output,'incseq.out');
        reset(input);
        rewrite(output);
	process;
        close(input);
        close(output);
END.
