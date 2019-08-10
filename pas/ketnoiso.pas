const
        fi='ketnoiso.inp';
        fo='ketnoiso.out';
var
        a:array [1..101] of string;
        s,s1:ansistring;
        t:string;
        n,i:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n);
        readln(f,s1);
        s1:=s1+' ';
        i:=1;
        while s1<>'' do
        begin
                a[i]:='';
                while s1[1]<>' ' do
                begin
                        a[i]:=a[i]+s1[1];
                        delete(s1,1,1);
                end;
                inc(i);
                delete(s1,1,1);
        end;
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v:longint;
        t:string;
        x:string;
begin
        u:=l;
        v:=r;
        x:=a[l+random(r-l+1)];
        repeat
                while a[u]>x do inc(u);
                while a[v]<x do dec(v);
                if u<=v then
                begin
                        t:=a[u];a[u]:=a[v];a[v]:=t;
                        inc(u);dec(v);
                end;
        until u>v;
        if u<r then sort(u,r);
        if l<v then sort(l,v);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        sort(1,n);
        s:='';
        repeat
        for i:=1 to n do
               if a[i]+a[i+1]<a[i+1]+a[i] then
               begin
                        t:=a[i];a[i]:=a[i+1];a[i+1]:=t;
                        break;
               end;
        until i=n;
                for i:=1 to n do
                        s:=s+a[i];
        write(f,s);
        close(f);
end;
begin
        nhap;
        xuly;

end.
