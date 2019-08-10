uses math;
var     s:array[1..1000000] of char;
        f:array[1..1000000] of longint;
        d,i,maxn,res,j,n:longint;
procedure nhap;
begin
        while not seekeof do
        begin
                inc(n);
                read(s[n]);
        end;
end;
procedure xuly;
begin
        d:=0;
        maxn:=0;
        if s[1]='7' then
        begin
                inc(d);
                inc(f[d]);
        end;
        for i:=2 to n do
                if s[i]='7' then
                begin
                        if s[i-1]='7' then inc(f[d])
                        else begin
                                if f[d]>maxn then maxn:=f[d];
                                inc(d);
                                inc(f[d]);
                        end;
                end;
        if f[d]>maxn then maxn:=f[d];
        for i:=1 to maxn do
        begin
                res:=0;
                for j:=1 to d do
                        inc(res,max(0,f[j]-i+1));
                writeln(i,' ',res);
        end;
end;
begin
        {assign(input,'vosseven.inp');
        assign(output,'vosseven.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output);}
end.