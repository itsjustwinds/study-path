const
        fi='artill.inp';
        fo='artill.out';
var
        a:array[0..101,0..101] of longint;
        n,m,d,i,j,k,x,k4,k8:longint;
        kt:array[1..101,1..101] of boolean;
        s:string;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        for i:=0 to n+1 do
                for j:=0 to m+1 do
                        a[i,j]:=0;
        for i:=1 to n do
        begin
                readln(f,s);
                for j:=1 to m do
                begin
                        val(s[j],a[i,j],x);
                        kt[i,j]:=true;
                end;
        end;
        close(f);
end;
procedure loan8(x,y:longint);
begin
        a[x,y]:=2;
        kt[x,y]:=false;
        inc(k8);
        if (a[x-1,y]=1) and kt[x-1,y] then loan8(x-1,y);
        if (a[x,y-1]=1) and kt[x,y-1] then loan8(x,y-1);
        if (a[x,y+1]=1) and kt[x,y+1] then loan8(x,y+1);
        if (a[x+1,y]=1) and kt[x+1,y] then loan8(x+1,y);
        if (a[x-1,y-1]=1) and kt[x-1,y-1] then
                loan8(x-1,y-1);
        if (a[x-1,y+1]=1) and kt[x-1,y+1] then
                loan8(x-1,y+1);
        if (a[x+1,y-1]=1) and kt[x+1,y-1] then
                loan8(x+1,y-1);
        if (a[x+1,y+1]=1) and kt[x+1,y+1] then
                loan8(x+1,y+1);
end;
procedure loan4(x,y:longint);
begin
        kt[x,y]:=true;
        inc(k4);
        if (a[x-1,y]=2) and kt[x-1,y] then loan4(x-1,y);
        if (a[x,y-1]=2) and kt[x,y-1] then loan4(x,y-1);
        if (a[x,y+1]=2) and kt[x,y+1] then loan4(x,y+1);
        if (a[x+1,y]=2) and kt[x+1,y] then loan4(x+1,y);
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        d:=0;
        for i:=1 to n do
                for j:=1 to m do
                        if (a[i,j]=1) and kt[i,j]=true then
                        begin
                                k8:=0;
                                loan8(i,j);
                                if (a[i,j]=2) and not kt[i,j] then
                                begin
                                        k4:=0;
                                        loan4(i,j);
                                end;
                                if k8>=k4*2 then d:=d+2
                                else inc(d);

                        end;
        write(f,d);
        close(f);
end;
begin
        nhap;
        xuly;
     { for i:=1 to n do
        begin
                for j:=1 to m do
                        write(a[i,j],' ');
                writeln;
        end;
        readln; }
end.
