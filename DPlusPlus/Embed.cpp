#include "Embed.h"

void Embed::ToJson(nJson &j) {
	nJson footerJson, imageJson, thumbnailJson, videoJson, providerJson, authorJson;

	footer.ToJson(footerJson);
	image.ToJson(imageJson);
	thumbnail.ToJson(thumbnailJson);
	video.ToJson(videoJson);
	provider.ToJson(providerJson);
	author.ToJson(authorJson);

	j = nJson{
		{"title",		title			},
		{"type",		type			},
		{"description",	description		},
		{"url",			url				},
		{"timestamp",	timestamp		},
		{"color",		color			},
		{"footer",		footerJson		},
		{"image",		imageJson		},
		{"thumbnail",	thumbnailJson	},
		{"video",		videoJson		},
		{"provider",	providerJson	},
		{"author",		authorJson		}
	};

	for(auto iter = fields.begin(); iter != fields.end(); ++iter) {
		j["fields"].push_back(*iter);
	}
}

void Embed::AddField(const std::string &name, const std::string &value, bool _inlineField) {
	nJson newField;

	newField["name"] = name;
	newField["value"] = value;
	newField["inline"] = _inlineField;

	fields.push_back(newField);
}

void Embed_Footer::ToJson(nJson &j) {
	j = nJson{
		{"text",			text			},
		{"icon_url",		icon_url		},
		{"proxy_icon_url",	proxy_icon_url	}
	};
}

void Embed_Image::ToJson(nJson &j) {
	j = nJson{
		{"url",			url			},
		{"proxy_url",	proxy_url	},
		{"height",		height		},
		{"width",		width		}
	};
}

void Embed_Thumbnail::ToJson(nJson &j) {
	j = nJson{
		{"url",			url			},
		{"proxy_url",	proxy_url	},
		{"height",		height		},
		{"width",		width		}
	};
}

void Embed_Video::ToJson(nJson &j) {
	j = nJson{
		{"url",			url			},
		{"proxy_url",	proxy_url	},
		{"height",		height		},
		{"width",		width		}
	};
}

void Embed_Provider::ToJson(nJson &j) {
	j = nJson{
		{"name",	name	},
		{"url",		url		}
	};
}

void Embed_Author::ToJson(nJson &j) {
	j = nJson{
		{"name",			name			},
		{"url",				url				},
		{"icon_url",		icon_url		},
		{"proxy_icon_url",	proxy_icon_url	}
	};
}
