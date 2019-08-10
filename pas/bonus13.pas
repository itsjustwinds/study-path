uses math;
const
        n=8;
var
        f:array[1..8,1..8] of longint;
        dd:array[1..8,1..8] of longint;
        fr:array[1..8,1..8] of boolean;
        dx,cx,hx:array[1..8] of integer;
        dy,cy,hy:array[1..8] of integer;
        x,y:array[1..3] of longint;
        i,j,k,tt:longint;
        res:int64;
procedure check;
var     u,v,k,i,j,h:longint;
        cross1,cross2:array[1..8] of int64;
        tmp:int64;
begin
        inc(tt);
        tmp:=0;
        i:=x[1];j:=y[1];
        for k:=1 to 4 do
        begin
                u:=i+dx[k];v:=j+dy[k];
                while (u>=1) and (u<=8) and (v<=8) and (v>=1) do
                begin
                        if dd[u,v]<tt then
                        begin
                                dd[u,v]:=tt;
                                inc(tmp,f[u,v]);
                        end;
                        u:=u+dx[k];v:=v+dy[k];
                end;
        end;
        for k:=1 to 4 do
        begin
                u:=i+cx[k];v:=j+cy[k];
                while (u>=1) and (u<=8) and (v>=1) and (v<=8) do
                begin
                        if dd[u,v]<tt then
                        begin
                                dd[u,v]:=tt;
                                inc(tmp,f[u,v]);
                        end;
                        u:=u+cx[k];v:=v+cy[k];
                end;
        end;
        i:=x[2];j:=y[2];
        for k:=1 to 4 do
        begin
                u:=i+cx[k];v:=j+cy[k];
                while (u>=1) and (u<=8) and (v>=1) and (v<=8) do
                begin
                        if dd[u,v]<tt then
                        begin
                                dd[u,v]:=tt;
                                inc(tmp,f[u,v]);
                        end;
                        u:=u+cx[k];v:=v+cy[k];
                end;
        end;
        i:=x[3];j:=y[3];
        for k:=1 to 8 do
                if (i+hx[k]<=8) and (i+hx[k]>=1) and (j+hy[k]<=8) and (j+hy[k]>=1) then
                if dd[i+hx[k],j+hy[k]]<tt then
                begin
                        dd[i+hx[k],j+hy[k]]:=tt;
                        inc(tmp,f[i+hx[k],j+hy[k]]);
                end;
        fillchar(cross1,sizeof(cross1),0);
        fillchar(cross2,sizeof(cross2),0);
        for i:=1 to n do
                for j:=1 to n do
                        if dd[i,j]<tt then
                        begin
                                inc(cross1[i],f[i,j]);
                                inc(cross2[j],f[i,j]);
                        end;
        for i:=1 to n do
                for j:=1 to n do
                if fr[i,j] then
                begin
                        if dd[i,j]<tt then h:=0 else h:=f[i,j];
                        res:=max(res,tmp+cross1[i]+cross2[j]-h);
                end;
end;
procedure try(v:longint);
var     i,j,k:longint;
begin
        if v=4 then check
        else
        begin
                for i:=1 to 8 do
                        for j:=1 to 8 do
                        if fr[i,j] then
                        begin
                                fr[i,j]:=false;
                                x[v]:=i;y[v]:=j;
                                try(v+1);
                                fr[i,j]:=true;
                        end;
        end;
end;
procedure nhap;
var     x,y,v:longint;
begin
        dx[1]:=-1;dx[2]:=0;dx[3]:=1;dx[4]:=0;
        dy[1]:=0;dy[2]:=1;dy[3]:=0;dy[4]:=-1;
        cx[1]:=-1;cx[2]:=-1;cx[3]:=1;cx[4]:=1;
        cy[1]:=-1;cy[2]:=1;cy[3]:=1;cy[4]:=-1;
        hx[1]:=-1;hx[2]:=-2;hx[3]:=-2;hx[4]:=-1;
        hx[5]:=1;hx[6]:=2;hx[7]:=2;hx[8]:=1;
        hy[1]:=-2;hy[2]:=-1;hy[3]:=1;hy[4]:=2;
        hy[5]:=2;hy[6]:=1;hy[7]:=-1;hy[8]:=-2;
        fillchar(fr,sizeof(fr),true);
        readln(k);
        for i:=1 to k do
        begin
                readln(x,y,v);
                fr[x,y]:=false;
                f[x,y]:=v;
        end;
        tt:=0;
        try(1);
        writeln(res);
end;
begin
        {assign(input,'bonus13.inp');
        assign(output,'bonus13.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output); }
end.