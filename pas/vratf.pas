var
        res:int64;
        k,n:longint;
function tinh(n:longint):longint;
begin
        if ((n mod 2)<>(k mod 2)) or (n<=k+1) then exit(1);
        exit(tinh(n div 2+((k+1) div 2))+tinh(n-(n div 2+((k+1) div 2))));
end;
procedure nhap;
begin
        readln(n,k);
        res:=tinh(n);
        writeln(res);
end;
begin
        {assign(input,'vraft.inp');
        assign(output,'vraft.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.