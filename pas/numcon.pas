const
        fi='numcon.inp';
        fo='numcon.out';
var
        a:array [1..101] of string;
        k,i:longint;
        t,s:string;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        k:=0;
        while not (eof(f)) do
        begin
        inc(k);
        readln(f,a[k]);
        end;
        close(f);
end;
procedure sort(l,r:longint);
var
        u,v:longint;
        x,t:string;
begin
        u:=l;v:=r;
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
{function sosanh(s,s1:string):boolean;
begin
        while length(s)<>length(s1) do
        begin
                if length(s)<length(s1) then s:=s+'0';
                if length(s)>length(s1) then s1:=s1+'0';
        end;
        if s>s1 then sosanh:=true
        else sosanh:=false;
end;                   }
procedure xuly;
var i:longint;
begin
        assign(f,fo);
        rewrite(f);  sort(1,k);
        s:='';
        for i:=1 to k do
                if {sosanh(a[i],a[i+1])=false}a[i]+a[i+1]<a[i+1]+a[i] then
                        begin
                        t:=a[i];a[i]:=a[i+1];a[i+1]:=t;
                        end;
        for i:=1 to k do
                s:=s+a[i];
        write(f,s);
        close(f);
end;
begin
        nhap;
        xuly;
      { sort(1,k);
       for i:=1 to k do
        writeln(a[i]);
        readln;}
end.
