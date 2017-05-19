#ifndef PROTOCOL_H
#define PROTOCOL_H

AccountType

'type' TEXT NOT NULL,
PRIMARY KEY(type)

AccountStatus

'status' TEXT NOT NULL,
PRIMARY KEY(status)

Accounts

'account' TEXT NOT NULL,
'password' TEXT NOT NULL,
'display' TEXT DEFAULT '',
'type' TEXT NOT NULL,
'status' TEXT NOT NULL,
PRIMARY KEY(account),
FOREIGN KEY(type) REFERENCES AccountType(type)
FOREIGN KEY(status) REFERENCES AccountStatus(status)

DeviceType

'type' TEXT NOT NULL,
PRIMARY KEY(type)

DeviceStatus

'status' TEXT NOT NULL,
PRIMARY KEY(status)

DeviceVAD

'vad' TEXT NOT NULL,
PRIMARY KEY(vad)

Devices

'mac' TEXT NOT NULL,
'seleted' INTEGER DEFAULT '0',
'type' TEXT NOT NULL,
'status' TEXT NOT NULL,
'vad' TEXT NOT NULL,
'name' TEXT NOT NULL,
'battery_percent' INTEGER DEFAULT '0',
'battery_time' INTEGER DEFAULT '0',
'owner' TEXT NOT NULL,
PRIMARY KEY(mac),
FOREIGN KEY(type) REFERENCES DeviceType(type),
FOREIGN KEY(status) REFERENCES DeviceStatus(status),
FOREIGN KEY(vad) REFERENCES DeviceVAD(vad),
FOREIGN KEY(owner) REFERENCES Accounts(account)

ConferencType

'type' TEXT NOT NULL,
PRIMARY KEY(type)

Conferencs

'uuid' TEXT NOT NULL,
'type' TEXT NOT NULL,
'title' TEXT NOT NULL,
'description' TEXT NOT NULL,
'members' TEXT NOT NULL,
'members' TEXT NOT NULL,
'create_time' TEXT NOT NULL,
'update_time' TEXT NOT NULL,
'completed' INTEGER DEFAULT '0',
'downloaded' INTEGER DEFAULT '0',
PRIMARY KEY(uuid)

FileType

'type' TEXT NOT NULL,
PRIMARY KEY(type)

FileSuffix

'suffix' TEXT NOT NULL,
PRIMARY KEY(suffix)

Files

'path' TEXT NOT NULL,
'type' TEXT NOT NULL,
'suffix' TEXT NOT NULL,
'conference' TEXT NOT NULL,
'owner' TEXT NOT NULL,
'device' TEXT NOT NULL,
'time_drift' INTEGER DEFAULT '0',
PRIMARY KEY(path),
FOREIGN KEY(type) REFERENCES Conferencs(type),
FOREIGN KEY(suffix) REFERENCES Conferencs(suffix),
FOREIGN KEY(conference) REFERENCES Conferencs(uuid),
FOREIGN KEY(owner) REFERENCES Accounts(account),
FOREIGN KEY(device) REFERENCES Devices(mac)

Downloads

'id' INTEGER NOT NULL,
'conference' TEXT NOT NULL,
'owner' TEXT NOT NULL,
'startpos' INTEGER NOT NULL,
'data_size' INTEGER DEFAULT '0',
'data' BLOB DEFAULT '',
'completed' INTEGER DEFAULT '0',
'path' TEXT NOT NULL,
PRIMARY KEY(id),
FOREIGN KEY(conference) REFERENCES Conferencs(uuid),
FOREIGN KEY(owner) REFERENCES Accounts(account)


mode:auth
action:login

userId
userGroup(default "ND")
userName
deviceType(PC,ANDROID,IOS)


mode:info
action:push
data:{
    deviceName
    batteryPercent
    batteryTime
    status
    vad
}

mode:info
action:pull
data:{
    list:[
    {
    userId
    userType(default "ND")
    userName
    deviceType(PC,ANDROID,IOS)
    deviceName
    batteryPercent
    batteryTime
    status
    vad
    },
    {
    userId
    userType(default "ND")
    userName
    deviceType(PC,ANDROID,IOS)
    deviceName
    batteryPercent
    batteryTime
    status
    vad
    }
    ]
}


mode:conference
action:lock/unlock
data:{
    userId:[

    ]
}

mode:conference
action:lock/unlock
data:{
    userId:string
    result:boolean
}

mode:conference
action:create
data:{
    title:string（非必须）
    content:string（非必须）
    members:string （非必须）
    user:[

    ]
}


mode:conference
action:create
data:{
    result:boolean
    title:string（非必须）
    content:string（非必须）
    members:string （非必须）
    create_time:string
    update_time:string
    uuid:string
    status:string
    user:[

    ]
}


mode:conference/personal/mobile
action:query
data:{
    uuid:string
}


mode:conference/personal/mobile
action:query
data:{
    result:boolean
    list:[
    {
    title:string（非必须）
    content:string（非必须）
    members:string （非必须）
    create_time:string
    update_time:string
    uuid:string
    status:string
    user:[

    ]
    },
    {
    title:string（非必须）
    content:string（非必须）
    members:string （非必须）
    create_time:string
    update_time:string
    uuid:string
    status:string
    user:[

    ]
    }
    ]
}


mode:conference
action:join/leave
data:{
    userId:string
    uuid:
}


mode:conference
action:join/leave
data:{
    result:boolean
    userId:string
    uuid:
}


mode:conference
action:start/resume/pause/stop
data:{
    uuid:string
}


mode:conference
action:start/resume/pause/stop
data:{
    result:boolean
    uuid:string
}

mode:conference/personal/mobile
action:edit/delete
data:{
    uuid:string
    title:string
    content:string
    members:string
}


mode:conference/personal/mobile
action:edit/delete
data:{
    result:boolean
    uuid:string
    title:string
    content:string
    members:string
}


mode:mobile
action:join/leave
data:{
    code:string
}

mode:mobile
action:join/leave
data:{
    result:boolean
    uuid:string
}


#endif // PROTOCOL_H
