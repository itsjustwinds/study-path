const
        fi='prodig.inp';
        fo='prodig.out';
var
        d,dem,k,h,i,x:longint;
        n:int64;
        s,s1:string;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        close(f);
end;
function nt(n:longint):boolean;
var     i:longint;
begin
        nt:=false;
        if n<2 then exit;
        for i:=2 to trunc(sqrt(n)) do
                if n mod i=0 then exit;
        nt:=true;
end;
procedure sort(l,r:longint);
var
        u,v:longint;
        x,t:char;
begin
        u:=l;v:=r;x:=s[(l+r) div 2];
        repeat
                while s[u]<x do inc(u);
                while s[v]>x do dec(v);
                if u<=v then
                begin
                        t:=s[u];s[u]:=s[v];s[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if l<v then sort(l,v);
        if u<r then sort(u,r);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        k:=2;
        s:='';
        if n=1 then s:='1';
        if (n>=11) and (nt(n)) then s:='-1';
        if (not(nt(n)))and(n>=2) then
        while n<>1 do
        begin
             if n mod k=0 then
             begin
                dem:=0;
                if (k=2) or (k=3) then
                begin
                        while n mod k=0 do
                        begin
                                inc(dem);
                                n:=n div k;
                        end;
                        if k=2 then
                        begin
                                h:=dem div 3;
                                dem:=dem mod 3;
                        end;
                        if k=3 then
                        begin
                                h:=dem div 2;
                                dem:=dem mod 2;
                        end;
                        for i:=1 to h do
                                if k=2 then
                                begin
                                        str(2*2*2,s1);
                                        s:=s+s1;
                                end
                                else begin
                                        str(3*3,s1);
                                        s:=s+s1;
                                end;
                        if dem<>0 then
                                if k=2 then
                                begin
                                        str(2*dem,s1);
                                        s:=s+s1;
                                end
                                else begin
                                        str(3,s1);
                                        s:=s+s1;
                                end;
                end
                else while n mod k=0 do
                begin
                        str(k,s1);
                        s:=s+s1;
                        n:=n div k;
                end;
             end;
             inc(k);
             if k>n then
                break;
        end;
        if s='' then s:='-1';
        sort(1,length(s));
        val(s,n,x);
        write(f,n);
        close(f);
end;
begin
        nhap;
        xuly;
end.
