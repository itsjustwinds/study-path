const
        fi='chianhom.inp';
        fo='chianhom.out';
var
        n,k,t:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,k);
        close(f);
end;
procedure chiale(n:longint);
begin
        if (n mod 2=0) or(n<=k) then
        begin
                inc(t);
                exit;
        end;
        if n mod 2=1 then
        begin
                chiale(n div 2+k div 2+1);
                chiale(n div 2-k div 2);
        end;
end;
procedure chiachan(n:longint);
begin
        if (n mod 2=1) or (n<=k) then
        begin
                inc(t);
                exit;
        end;
        if n mod 2=0 then
        begin
                chiachan(n div 2+k div 2);
                chiachan(n div 2-k div 2);
        end;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        t:=0;
        if k mod 2=1 then chiale(n);
        if k mod 2=0 then chiachan(n);
        write(f,t);
        close(f);
end;
begin
        nhap;
        xuly;
end.
