import { Configs, Config } from './config.type';

const configs: Configs = {
    en: {
        name: "Young Lee",
        title: `* Young Lee's CV, press [Q] to exit, [↑→↓←] to navigate *`,
        remoteUrl: 'https://raw.githubusercontent.com/YoungLeeNENU/younglee/node-version/info/',
        items: [
            [''],
            ['Overview'],
            ['Education'],
            ['Work Experience'],
            ['Projects'],
            ['Skills'],
            ['Links']
        ],
        info: ['',
            'basic.en.md',
            'education.en.md',
            'work.en.md',
            'project.en.md',
            'skills.en.md',
            'links.en.md'
        ]
    },
    ch: {
        name: "李旸",
        title: '* 李旸的简历，按 [Q] 退出，按 [↑→↓←] 导航 *',
        remoteUrl: 'https://raw.githubusercontent.com/YoungLeeNENU/younglee/node-version/info/',
        items: [
            [''],
            ['基本信息'],
            ['教育情况'],
            ['工作经历'],
            ['项目'],
            ['技能'],
        ],
        info: ['',
            'basic.ch.md',
            'education.ch.md',
            'work.ch.md',
            'project.ch.md',
            'skills.ch.md',
            'links.ch.md'
        ]
    }
};

export default configs;
