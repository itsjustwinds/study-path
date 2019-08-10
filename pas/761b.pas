var     fa,fb:array[0..1000] of longint;
        a,b:array[0..1000] of longint;
        n,i,l:longint;
function kt(vt:longint):boolean;
var     i,j:longint;
begin
        for i:=1 to n-1 do
                if fb[i]<>fa[i+vt-1] then exit(false);
        exit(true);
end;
procedure nhap;
begin
        readln(n,l);
        for i:=1 to n do
                read(a[i]);
        for i:=1 to n do
                read(b[i]);
        for i:=1 to n-1 do
                a[n+i]:=a[i];
        for i:=1 to 2*n-2 do
                fa[i]:=abs(a[i+1]-a[i]);
        for i:=1 to n-1 do
                fb[i]:=abs(b[i+1]-b[i]);
        for i:=1 to n do
                if kt(i) then
                begin
                        writeln('YES');
                        exit;
                end;
        writeln('NO');
end;
begin
        assign(input,'761b.inp');
        assign(output,'761b.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.