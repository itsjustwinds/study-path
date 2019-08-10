var
        a:array[1..1000,1..1000] of boolean;
        dd:array[1..1000] of boolean;
        n,m,i,j,x,y,dem:longint;
procedure nhap;
begin
        readln(n,m);
        fillchar(a,sizeof(a),false);
        for i:=1 to n do
                a[i,i]:=true;
        for i:=1 to m do
        begin
                readln(x,y);
                a[x,y]:=true;
                a[y,x]:=true;
        end;
end;
procedure xuly;
var i,j,k:Longint;
begin
        fillchar(dd,sizeof(dd),true);
        for i:=1 to n do
        for j:=1 to n do
        for k:=1 to n do
                a[j,k]:=a[j,k] or a[i,j] and a[i,k];
        dem:=0;
        for i:=1 to n do
        if dd[i] then
        begin
                inc(dem);
                writeln('mien lien thong ',dem,':');
                for j:=1 to n do
                        if a[i,j] then
                        begin
                                dd[j]:=false;
                                write(j,' ');
                        end;
                writeln;
        end;
end;
begin
        assign(input,'conectivity.inp');
        assign(output,'conectivity.out');
        reset(input);
        rewrite(output);
        nhap;
        xuly;
        close(input);
        close(output);
end.
