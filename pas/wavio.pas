const
fi='wavio.inp';
fo='wavio.out';
var
        a,l,g:array[0..10001] of longint;
        i,j,d,n,max,min:longint;
        f,h:text;
procedure xuly;
begin
        fillchar(l,sizeof(l),0);
        fillchar(g,sizeof(g),0);
        l[1]:=1;
        g[n]:=1;
        for i:=2 to n do
        begin
                l[i]:=1;
                for j:=1 to i-1 do
                        if (a[j]<a[i]) and (l[j]+1>l[i]) then
                        l[i]:=l[j]+1;
        end;
        for i:=n-1 downto 1 do
        begin
                g[i]:=1;
                for j:=n downto i+1 do
                        if (a[i]>a[j]) and (g[j]+1>g[i]) then
                        g[i]:=g[j]+1;
        end;
        max:=0;
        for i:=1 to n do
        begin
                if l[i]<g[i] then min:=l[i] else min:=g[i];
                if min>max then max:=min;
        end;
        writeln(h,2*max-1);
end;
procedure nhap;
begin
        assign(f,fi);
        assign(h,fo);
        reset(f);
        rewrite(h);
        while not eof(f) do
        begin
        readln(f,n);
        for i:=1 to n do
                read(f,a[i]);
                xuly;
        end;
        close(f);
        close(h);
end;
begin
        nhap;
end.